/*
文件服务器
*/

#ifndef FILESERVER_H
#define FILESERVER_H

#include <QTcpServer>

class FileServer : public QTcpServer
{
    Q_OBJECT

public:
    static FileServer *getInstance();
    static FileServer *releaseInstance();

    void configure(QHostAddress, short);
    bool start();

private:
    QHostAddress host;
    short port;

    virtual void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;

    // singleton implemented
    static FileServer *fserver;
    explicit FileServer(QObject *parent = nullptr);
    ~FileServer();

private slots:
    void _recvMsg();
    void _disconnect();
};

#endif // FILESERVER_H
