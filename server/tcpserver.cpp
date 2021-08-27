#include "tcpserver.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

TcpServer *TcpServer::me = nullptr;

TcpServer::TcpServer(QObject *parent) : QTcpServer(parent)
{
}

void TcpServer::initiate(QHostAddress _addr, quint16 _port)
{
    this->addr = _addr;
    this->port = _port;
}

void TcpServer::start()
{
    this->listen(this->addr, this->port);
}

TcpServer::~TcpServer()
{
    for (auto _iter = unconnList.rbegin(); _iter != unconnList.rend(); ++_iter) {
        (*_iter)->close();
        delete *_iter;
    }
    for (auto _iter = connList.begin(); _iter != connList.end(); ++_iter) {
        (*_iter)->close();
        delete *_iter;
    }
    close();
}

TcpServer *TcpServer::getInstance()
{
    return (me == nullptr) ? (me = new TcpServer) : me;
}

// 每次新增连接的时候，都会新增一个监听这个连接的socket
void TcpServer::incomingConnection(qintptr _handle)
{
    QTcpSocket *_socket = new QTcpSocket;
    _socket->setSocketDescriptor(_handle);
    unconnList.append(_socket);

    connect(_socket, &QTcpSocket::readyRead, this, &TcpServer::_recvMsg);
    connect(_socket, &QTcpSocket::disconnected, this, &TcpServer::_disconnected);
}

void TcpServer::_recvMsg()
{
    ;
}

void TcpServer::_disconnected()
{
    ;
}

void TcpServer::_sendMsg(QTcpSocket *_skt, const QString &msg)
{
    Q_UNUSED(_skt);
    qDebug() << msg;
//    _skt->write(msg.toUtf8());
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
                               , const QList<QPair<QString, QString>> &_list)
{
    QJsonObject _json = this->prepareSendJson("friendList");
    QJsonDocument _doc;
    QJsonArray _array;

    auto _size = _list.size();
    for (int i = 0; i < _size; ++i) {
        QJsonObject _tmp;
        _tmp.insert("id", _list[i].first);
        _tmp.insert("name", _list[i].second);
        _array.append(_tmp);
    }

    _json.insert("value", _array);
    _doc.setObject(_json);
    _sendMsg(_skt, _doc.toJson(QJsonDocument::Compact));
}

void TcpServer::sendChatMsg(QTcpSocket *_skt, const QString &_from
                            , const QString &_to, const QString &_date
                            , const QString &_msg)
{
    QJsonObject _json = this->prepareSendJson("messageTransmit");
    QJsonObject _value;
    QJsonDocument _doc;
    _value.insert("from", _from);
    _value.insert("to", _to);
    _value.insert("date", _date);
    _value.insert("value", _msg);

    _json.insert("value", _value);

    _doc.setObject(_json);
    _sendMsg(_skt, _doc.toJson(QJsonDocument::Compact));
}


