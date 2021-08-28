#include "clienttcpsocket.h"

ClientTcpSocket::ClientTcpSocket(QObject* parent)
    : QObject(parent)
{
    initialLize();
}

void ClientTcpSocket::initialLize()
{
    clientSocket = new QTcpSocket(this);
    clientSocket->connectToHost("127.0.0.1", 6666);
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(_recvMsg()));
}

QJsonObject ClientTcpSocket::client_prepareSendJson(const QString& quest)
{
    QJsonObject _result;
    _result.insert("sender", "client");
    _result.insert("quest", quest);
    return _result;
}

void ClientTcpSocket::sendloginMsg(const QString& username, const QString& pwd)
{
    QJsonObject _json = this->client_prepareSendJson("loginQuest");
    QJsonObject _value;
    QJsonDocument _doc;
    _value.insert("username", username);
    _value.insert("pwd", pwd);
    _json.insert("value", _value);
    _doc.setObject(_json);
    clientSocket->write(_doc.toJson(QJsonDocument::Compact));
}

void ClientTcpSocket::sendRegMsg(const QString& username, const QString& pwd)
{
    QJsonObject _json = this->client_prepareSendJson("registerQuest");
    QJsonObject _value;
    QJsonDocument _doc;
    _value.insert("username", username);
    _value.insert("pwd", pwd);
    _json.insert("value", _value);
    _doc.setObject(_json);
    clientSocket->write(_doc.toJson(QJsonDocument::Compact));
}
void ClientTcpSocket::sendMsgTo(const QString& from_id, const QString& to_id,
    const QString& time, const QString& msg)
{
    QJsonObject _json = this->client_prepareSendJson("messageSend");
    QJsonObject _value;
    QJsonDocument _doc;
    _value.insert("from", from_id);
    _value.insert("to", to_id);
    _value.insert("time", time);
    _value.insert("value", msg);
    _json.insert("value", _value);
    _doc.setObject(_json);
    clientSocket->write(_doc.toJson(QJsonDocument::Compact));
}

void ClientTcpSocket::sendFriendAdd(const QString& id)
{
    QJsonObject _json = this->client_prepareSendJson("friendAddQuest");
    QJsonDocument _doc;
    _json.insert("value", id);
    _doc.setObject(_json);
    clientSocket->write(_doc.toJson(QJsonDocument::Compact));
}
void ClientTcpSocket::sendFriendDel(const QString& id)
{
    QJsonObject _json = this->client_prepareSendJson("friendAddQuest");
    QJsonDocument _doc;
    _json.insert("value", id);
    _doc.setObject(_json);
    clientSocket->write(_doc.toJson(QJsonDocument::Compact));
}

void ClientTcpSocket::_recvMsg()
{
    QByteArray buf = clientSocket->readAll();
    QString value = buf;
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
        emit this->recvRegConMsg(regcon_value.value("id").toString());
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
                list[i].id = id;
                list[i].name = name;
            }
        }
        emit recvFriendList(list);
    } else if (type == "messageTransmit") {
        auto msg_value = jsonObject.value("value").toObject();
        struct chat_msg chatmsg;
        chatmsg.from_id = msg_value.value("from").toString();
        chatmsg.to_id = msg_value.value("to").toString();
        chatmsg.time = msg_value.value("time").toString();
        chatmsg.value = msg_value.value("value").toString();
        emit this->recvChatMsg(chatmsg);
    }
}
