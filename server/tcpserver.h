#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    ~TcpServer();
    void sendLoginConfirm(QTcpSocket*, QString);
    void sendRegConfirm(QTcpSocket*, QString);
    void sendFriendList(QTcpSocket*, QString);
    void sendChatMsg(QTcpSocket*, QString);

    static TcpServer *getInstance();

private:
    // 单例设计模式
    static TcpServer *me;
    // 连接但是没有登陆的socket
    QList<QTcpSocket*> unconnList;
    // 登录的用户的socket
    QMap<int, QTcpSocket*> connList;

    TcpServer(QObject *parent = nullptr);
    virtual void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;

    void recvLogin(QString);
    void recvRegister(QString);
    void recvMessage(QString);

private slots:
    // 槽函数，用于接受来信，并按照类别调用不同的函数处理
    void _recvMsg();
};

#endif // TCPSERVER_H
