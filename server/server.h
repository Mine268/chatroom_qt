#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    ~Server();
    void sendLoginConfirm(QTcpSocket*, QString);
    void sendRegConfirm(QTcpSocket*, QString);
    void sendFriendList(QTcpSocket*, QString);
    void sendChatMsg(QTcpSocket*, QString);

    Server *getInstance();

private:
    // 单例设计模式
    Server *me;
    // 已经连接但是没有登录的用户socket
    QList<QTcpSocket*> unconnList;
    // 已经登录的用户socket
    QMap<int, QTcpSocket*> connList;

    Server();
    virtual void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;

    void recvLogin(QString);
    void recvRegister(QString);
    void recvMessage(QString);

private slots:
    // 收到来自客户端的消息，本方法会预先分析消息属于哪一类，然后调用不同的方法处理
    void _recvMsg();
};

#endif // SERVER_H
