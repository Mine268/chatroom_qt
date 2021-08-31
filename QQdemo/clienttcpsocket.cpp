#include "clienttcpsocket.h"

QString ClientTcpSocket::getlocal()
{
    return "127.0.0.1";
}

ClientTcpSocket::ClientTcpSocket(QObject* parent)
    : QObject(parent)
{
    initialLize();
}

ClientTcpSocket::~ClientTcpSocket()
{
    qDebug() << "delete";
    delete clientSocket;
}

void ClientTcpSocket::initialLize()
{
    clientSocket = new QTcpSocket(this);
    clientSocket->connectToHost("10.195.22.79", 11451);
    if (!clientSocket->waitForConnected(3000)) {
        QMessageBox::information(nullptr, "QT网络通信", "连接服务端失败！");
        return;
    }
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(_recvMsg()));
}

QJsonObject ClientTcpSocket::client_prepareSendJson(const QString& quest)
{
    QJsonObject _result;
    _result.insert("sender", "client");
    _result.insert("quest", quest);
    return _result;
}

void ClientTcpSocket::write_wait(QByteArray data)
{
    clientSocket->waitForBytesWritten(400);
    clientSocket->write(data);
}

QString ClientTcpSocket::data_md5(QString pwd)
{
    //md5加密：将密码通过MD5加密后,将32位md5值,前后16位对调
    QString md5;
    QString str = pwd;
    QByteArray bb;
    bb = QCryptographicHash::hash(str.toLatin1(), QCryptographicHash::Md5);
    md5.append(bb.toHex());
    QString a = md5.mid(0, 16);
    QString b = md5.mid(16);
    QString str2 = b.append(a);

    return str2;
}

void ClientTcpSocket::sendloginMsg(const QString& id, const QString& pwd)
{
    QJsonObject _json = this->client_prepareSendJson("loginQuest");
    QJsonObject _value;
    QJsonDocument _doc;
    _value.insert("id", id);
    _value.insert("password", data_md5(pwd));
    _json.insert("value", _value);
    _doc.setObject(_json);
    write_wait(_doc.toJson(QJsonDocument::Compact));
}

void ClientTcpSocket::sendRegMsg(const QString& username, const QString& pwd)
{
    QJsonObject _json = this->client_prepareSendJson("registerQuest");
    QJsonObject _value;
    QJsonDocument _doc;
    _value.insert("username", username);
    _value.insert("password", data_md5(pwd));
    _json.insert("value", _value);
    _doc.setObject(_json);
    write_wait(_doc.toJson(QJsonDocument::Compact));
}
void ClientTcpSocket::sendMsgTo(QString from_id, QString to_id,
    QString time, QString msg)
{
    //ToDo
    QJsonObject _json = this->client_prepareSendJson("messageSend");
    QJsonObject _value;
    QJsonDocument _doc;
    _value.insert("from", from_id);
    _value.insert("to", to_id);
    _value.insert("time", time);
    _value.insert("value", msg);
    _json.insert("value", _value);
    _doc.setObject(_json);

    write_wait(_doc.toJson(QJsonDocument::Compact));
}

//void sendPicTo(const QString& from_id, const QString& to_id, const QString& time,
//    QByteArray picture)
//{
//   ;
//}

void ClientTcpSocket::sendFriendAdd(const QString& me_id, const QString& you_id)
{
    QJsonObject _json = this->client_prepareSendJson("friendAddQuest");
    QJsonObject _value;
    QJsonDocument _doc;
    _value.insert("me", me_id);
    _value.insert("you", you_id);
    _json.insert("value", _value);
    _doc.setObject(_json);
    write_wait(_doc.toJson(QJsonDocument::Compact));
}
void ClientTcpSocket::sendFriendDel(const QString& me_id, const QString& you_id)
{
    QJsonObject _json = this->client_prepareSendJson("friendDelQuest");
    QJsonObject _value;
    QJsonDocument _doc;
    _value.insert("me", me_id);
    _value.insert("you", you_id);
    _json.insert("value", _value);
    _doc.setObject(_json);
    write_wait(_doc.toJson(QJsonDocument::Compact));
}

void ClientTcpSocket::searchUser(const QString& me_id, const QString& you_id)
{
    QJsonObject _json = this->client_prepareSendJson("searchUserByID");
    QJsonObject _value;
    QJsonDocument _doc;
    _value.insert("sender_id", me_id);
    _value.insert("query_id", you_id);
    _json.insert("value", _value);
    _doc.setObject(_json);
    write_wait(_doc.toJson(QJsonDocument::Compact));
}

void ClientTcpSocket::sendFriendList(const QString& id)
{
    QJsonObject _json = this->client_prepareSendJson("friendList");
    QJsonObject _value;
    QJsonDocument _doc;
    _value.insert("id", id);
    _json.insert("value", _value);
    _doc.setObject(_json);
    write_wait(_doc.toJson(QJsonDocument::Compact));
}

void ClientTcpSocket::pullMessage(const QString& id)
{
    QJsonObject _json = this->client_prepareSendJson("pullHangedMessage");
    QJsonObject _value;
    QJsonDocument _doc;
    _value.insert("id", id);
    _json.insert("value", _value);
    _doc.setObject(_json);
    write_wait(_doc.toJson(QJsonDocument::Compact));
}

void ClientTcpSocket::_recvMsg()
{
    QByteArray buf = clientSocket->readAll();
    QString value = buf;

    qDebug() << "DDD: " << value;

    QJsonParseError parseJsonErr;
    QJsonDocument document = QJsonDocument::fromJson(value.toUtf8(), &parseJsonErr);
    if (!(parseJsonErr.error == QJsonParseError::NoError)) {
        qDebug() << tr("解析json文件错误！");
        return;
    }
    QJsonObject jsonObject = document.object();
    QString type = jsonObject["quest"].toString();
    QString msg = jsonObject["value"].toString();
    if (type == "loginConfirm")
        emit this->recvLoginConMsg("true");
    else if (type == "loginDeny")
        emit this->recvLoginDeMsg(msg); //登录失败的原因
    else if (type == "registerConfirm") {
        auto regcon_value = jsonObject.value("value").toObject();
        emit recvRegConMsg(regcon_value.value("id").toString());
    } else if (type == "registerDeny")
        emit this->recvRegDeMeg(msg); //注册失败的原因
    else if (type == "friendList") {
        QList<struct user> list;
        QJsonObject rootObj = document.object();
        QJsonValue arrValue = rootObj.value("value");
        if (arrValue.isArray()) // 判断获取的QJsonValue对象是不是数组结构
        {
            QJsonArray array = arrValue.toArray();
            for (int i = 0; i < array.size(); i++) {
                QJsonValue idValue = array.at(i);
                QJsonObject idObject = idValue.toObject();
                QString id = idObject["id"].toString();
                QString name = idObject["name"].toString();
                QString state = idObject["online"].toString();

                list.append({ id, name, "", state == "true" });
            }
        }
        emit recvFriendList(list);
    } else if (type == "messageTransmit") {

        QJsonArray jsonArr = jsonObject["value"].toArray();

        //        qDebug() << "[Clienttcpsocket messageTransmit]"
        //                 << "size: " << jsonArr.size();

        for (int i = 0; i < jsonArr.size(); ++i) {
            QJsonObject msg_value = jsonArr.at(i).toObject();

            struct chat_msg chatmsg;
            chatmsg.from_id = msg_value.value("from").toString();
            chatmsg.to_id = msg_value.value("to").toString();
            chatmsg.time = msg_value.value("time").toString();
            chatmsg.value = msg_value.value("value").toString();

            qDebug() << "[Clienttcpsocket messageTransmit]" << chatmsg.from_id << chatmsg.to_id;
            emit this->recvChatMsg(chatmsg);
        }
    } else if (type == "returnUserInfo") {
        auto msg_value = jsonObject.value("value").toObject();
        struct user userinfo;
        userinfo.id = msg_value.value("id").toString();
        userinfo.online = true;
        userinfo.email = msg_value.value("email").toString();
        userinfo.name = msg_value.value("name").toString();
        emit this->recvUserInfo(userinfo);
    }
    /*else if (type == "imageTransmit"){
        auto msg_value = jsonObject.value("value").toObject();
        struct pic_msg picmsg;
        picmsg.from_id = msg_value.value("from").toString();
        picmsg.to_id = msg_value.value("to").toString();
        picmsg.time = msg_value.value("time").toString();
        picmsg.pic = ;//待补充
        emit this->recvPicMsg(picmsg);
    }*/
}
