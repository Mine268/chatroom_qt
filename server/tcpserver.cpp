#include "tcpserver.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

TcpServer *TcpServer::me = nullptr;

TcpServer::TcpServer(QObject *parent) : QTcpServer(parent)
{
}

void TcpServer::configure(QHostAddress _addr, quint16 _port)
{
    this->addr = _addr;
    this->port = _port;
}

bool TcpServer::start()
{
    return this->listen(this->addr, this->port);
}

TcpServer::~TcpServer()
{
    close();
}

TcpServer *TcpServer::getInstance()
{
    return (me == nullptr) ? (me = new TcpServer) : me;
}

void TcpServer::releaseInstance()
{
    if (me != nullptr)
        delete me;
    me = nullptr;
}

// 每次新增连接的时候，都会新增一个监听这个连接的socket
void TcpServer::incomingConnection(qintptr _handle)
{
    QTcpSocket *_socket = new QTcpSocket;
    _socket->setSocketDescriptor(_handle);

    qDebug() << "[info]:" << _handle << "connected in TcpServer.";

    connect(_socket, &QTcpSocket::readyRead, this, &TcpServer::_recvMsg);
    connect(_socket, &QTcpSocket::disconnected, this, &TcpServer::_disconnected);
}

void TcpServer::_sendMsg(QTcpSocket *_skt, const QString &msg)
{
    _skt->waitForBytesWritten(300);
    _skt->write(msg.toUtf8());
}

QJsonObject TcpServer::prepareSendJson(const QString &_quest)
{
    QJsonObject _result;
    _result.insert("sender", "server");
    _result.insert("quest", _quest);
    return _result;
}

void TcpServer::sendLoginConfirm(QTcpSocket *_skt)
{
    QJsonObject _json = this->prepareSendJson("loginConfirm");
    QJsonDocument _doc;
    _json.insert("value", "true");

    _doc.setObject(_json);
    _sendMsg(_skt, _doc.toJson(QJsonDocument::Compact));
}

void TcpServer::sendLoginDeny(QTcpSocket *_skt, const QString &_msg)
{
    QJsonObject _json = this->prepareSendJson("loginDeny");
    QJsonDocument _doc;
    _json.insert("value", _msg);

    _doc.setObject(_json);
    _sendMsg(_skt, _doc.toJson(QJsonDocument::Compact));
}

void TcpServer::sendRegConfirm(QTcpSocket *_skt, const QString &_msg)
{
    QJsonObject _json = this->prepareSendJson("registerConfirm");
    QJsonObject _idObj;
    QJsonDocument _doc;

    _idObj.insert("id", _msg);
    _json.insert("value", _idObj);

    _doc.setObject(_json);
    _sendMsg(_skt, _doc.toJson(QJsonDocument::Compact));
}

void TcpServer::sendRegDeny(QTcpSocket *_skt, const QString &_msg)
{
    QJsonObject _json = this->prepareSendJson("registerDeny");
    QJsonDocument _doc;
    _json.insert("value", _msg);

    _doc.setObject(_json);
    _sendMsg(_skt, _doc.toJson(QJsonDocument::Compact));
}

void TcpServer::sendFriendList(QTcpSocket *_skt
                               , const QList<std::tuple<QString, QString, bool>> &_list)
{
    QJsonObject _json = this->prepareSendJson("friendList");
    QJsonDocument _doc;
    QJsonArray _array;

    auto _size = _list.size();
    for (int i = 0; i < _size; ++i) {
        QJsonObject _tmp;
        _tmp.insert("id", std::get<0>(_list[i]));
        _tmp.insert("name", std::get<1>(_list[i]));
        _tmp.insert("online", std::get<2>(_list[i]));
        _array.append(_tmp);
    }

    _json.insert("value", _array);
    _doc.setObject(_json);
    _sendMsg(_skt, _doc.toJson(QJsonDocument::Compact));
}

void TcpServer::sendChatMsg(QTcpSocket *_skt, const QList<DataDB::msgInfo> &_msgList)
{
    QJsonObject _json = this->prepareSendJson("messageTransmit");
    QJsonArray _valueArray;
    QJsonDocument _doc;

    for (auto it = _msgList.begin(); it != _msgList.end(); ++it) {
        QJsonObject _value;
        _value.insert("from", QString::number(it->from));
        _value.insert("to", QString::number(it->to));
        _value.insert("time", it->time);
        _value.insert("value", it->msg);

        _valueArray.append(_value);
    }

    _json.insert("value", _valueArray);
    _doc.setObject(_json);
    _sendMsg(_skt, _doc.toJson(QJsonDocument::Compact));
}

void TcpServer::sendChatImg(QTcpSocket *_skt, const QString &_from
                            , const QString &_to, const QString &_date
                            , const QString &_msg)
{
    QJsonObject _json = this->prepareSendJson("imageTransmit");
    QJsonObject _value;
    QJsonDocument _doc;
    _value.insert("from", _from);
    _value.insert("to", _to);
    _value.insert("time", _date);
    _value.insert("value", _msg);

    _json.insert("value", _value);

    _doc.setObject(_json);
    _sendMsg(_skt, _doc.toJson(QJsonDocument::Compact));
}

void TcpServer::sendUserInfo(QTcpSocket *_skt, const qint64 _id, const QString &_name, const QString &_email)
{
    QJsonObject _json = this->prepareSendJson("returnUserInfo");
    QJsonObject _value;
    QJsonDocument _doc;
    _value.insert("id", QString::number(_id));
    _value.insert("name", _name);
    _value.insert("email", _email);

    _json.insert("value", _value);

    _doc.setObject(_json);
    _sendMsg(_skt, _doc.toJson(QJsonDocument::Compact));
}

void TcpServer::_recvMsg()
{
    // 通过socket接受客户端发来的信息
    auto _socket = (dynamic_cast<QTcpSocket*>(this->sender()));
    auto _msg = _socket->readAll();

    qDebug() << "[recv json]:" << QString::fromUtf8(_msg);

    // 进行json解析
    QJsonParseError _jerror;
    QJsonDocument _jdoc = QJsonDocument::fromJson(_msg, &_jerror);

    if (_jerror.error == QJsonParseError::NoError && _jdoc.isObject()) {
        auto _jobj = _jdoc.object();
        auto _sender = _jobj.value("sender").toString();
        if (_sender == "client") {
            auto _quest = _jobj.value("quest").toString();
            // 因为在当前的设计中，所有的value必然是object，所以这里先一步转换
            auto _value = _jobj.value("value").toObject();

            if (_quest == "loginQuest") {
                emit this->recvLogin(_socket, _value.value("id").toString()
                                     , _value.value("password").toString());
            } else if (_quest == "registerQuest") {
                emit this->recvRegister(_socket, _value.value("username").toString()
                                        , _value.value("password").toString());
            } else if (_quest == "messageSend") {
                emit this->recvMessage(_value.value("from").toString()
                                       , _value.value("to").toString()
                                       , _value.value("time").toString()
                                       , _value.value("value").toString());
            } else if (_quest == "friendAddQuest") {
                emit this->recvFriendAddQuest(_value.value("me").toString(),
                                              _value.value("you").toString());
            } else if (_quest == "friendDelQuest") {
                emit this->recvFriendDelQuest(_value.value("me").toString(),
                                              _value.value("you").toString());
            } else if (_quest == "friendList") {
                emit this->recvFriendListQuest(_value.value("id").toString());
            } else if(_quest == "image") {
                emit this->recvImage(_value.value("from").toString()
                                     , _value.value("to").toString()
                                     , _value.value("time").toString()
                                     , _value.value("value").toString());
            } else if (_quest == "searchUserByID") {
                emit this->recvUserQuery(_value.value("query_id").toString().toLongLong()
                                         ,_value.value("sender_id").toString().toLongLong());
            } else if (_quest == "pullHangedMessage" ) {
                emit this->recvPullHangedMsg(_jobj.value("value").toString().toLongLong());
            } else {
                qDebug() << "[unknow request]:" << _quest;
            }

        } else {
            qDebug() << "[wrong sender]:" << _sender;
        }

    } else if (_jdoc.isObject()) {
        qDebug() << "[unmatched json type]:" << QString::fromUtf8(_msg);
    } else {
        qDebug() << "[json parse error]:" << QString::fromUtf8(_msg);
    }
}


void TcpServer::_disconnected()
{
    auto _socket = dynamic_cast<QTcpSocket*>(sender());
    qDebug() << "[tcpserver _disconnect]" << _socket;
    emit usrDisconnectedEx(_socket);
}

