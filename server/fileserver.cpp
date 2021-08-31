#include "fileserver.h"

#include <QTcpSocket>

FileServer *FileServer::fserver = nullptr;

FileServer *FileServer::getInstance()
{
    return (fserver == nullptr) ? (fserver = new FileServer) : fserver;
}

FileServer *FileServer::releaseInstance()
{
    if (!fserver) delete fserver;
    return fserver = nullptr;
}

void FileServer::configure(QHostAddress _host, short _port)
{
    host = _host;
    port = _port;
}

bool FileServer::start()
{
    return this->listen(host, port);
}

void FileServer::incomingConnection(qintptr handle)
{
    auto socket = new QTcpSocket;
    socket->setSocketDescriptor(handle);

    qDebug() << "[fileserver]:" << handle << "connected in FileServer";

    connect(socket, &QTcpSocket::readyRead, this, &FileServer::_recvMsg);
    connect(socket, &QTcpSocket::disconnected, this, &FileServer::_disconnect);
}

FileServer::FileServer(QObject *parent) : QTcpServer(parent)
{
}

FileServer::~FileServer()
{
    close();
}

void FileServer::_recvMsg()
{
    auto socket = dynamic_cast<QTcpSocket*>(sender());
    auto rawData = socket->readAll();

    qDebug() << "[FileServer _recvMsg]:" << "length:" << rawData.length();
}

void FileServer::_disconnect()
{
    auto socket = dynamic_cast<QTcpSocket*>(sender());
    qDebug() << "[FileServer _dissconnected]:"
             << socket << "dropeed, memory released by tcpsocket";
}
