#include "tcpserver.h"

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
    for (auto iter = unconnList.rbegin(); iter != unconnList.rend(); ++iter)
        (*iter)->close();
    for (auto iter = connList.begin(); iter != connList.end(); ++iter)
        (*iter)->close();
    close();
}

TcpServer *TcpServer::getInstance()
{
    return (me == nullptr) ? (me = new TcpServer) : me;
}

// 每次新增连接的时候，都会新增一个监听这个连接的socket
void TcpServer::incomingConnection(qintptr handle)
{
    QTcpSocket *_socket = new QTcpSocket;
    _socket->setSocketDescriptor(handle);
    unconnList.append(_socket);

    connect(_socket, &QTcpSocket::readyRead, this, &TcpServer::_recvMsg);
    connect(_socket, &QTcpSocket::disconnected, this, &TcpServer::_disconnected);
}
