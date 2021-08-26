#include "server.h"

Server *Server::me = nullptr;

Server::Server(QObject *parent) : QTcpServer(parent)
{
    this->listen(QHostAddress::Any, 11451);
}

Server::~Server()
{
    for (auto iter = unconnList.rbegin(); iter != unconnList.rend(); ++iter)
        (*iter)->close();
    for (auto iter = connList.begin(); iter != connList.end(); ++iter)
        (*iter)->close();
}

Server *Server::getInstance()
{
    return (me == nullptr) ? (me = new Server) : me;
}

// 每次新增连接的时候，都会新增一个监听这个连接的socket
void Server::incomingConnection(qintptr handle)
{
    QTcpSocket *_socket = new QTcpSocket;
    _socket->setSocketDescriptor(handle);
    unconnList.append(_socket);

    connect(_socket, &QTcpSocket::readyRead, this, &Server::_recvMsg);
}
