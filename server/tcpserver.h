#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    ~TcpServer();

    // 设置服务器监听
    void initiate(QHostAddress, quint16);
    // 服务器开始监听
    void start();

    void sendLoginConfirm(QTcpSocket*);
    void sendLoginDeny(QTcpSocket*, const QString&);
    void sendRegConfirm(QTcpSocket*, const QString&);
    void sendRegDeny(QTcpSocket*, const QString&);
    void sendFriendList(QTcpSocket*, const QList<QPair<QString, QString>>&);
    void sendChatMsg(QTcpSocket*, const QString&, const QString&
                     , const QString&, const QString&);

    static TcpServer *getInstance();

private:
    // 单例设计模式
    static TcpServer *me;
    // 服务器地址
    QHostAddress addr;
    // 监听端口
    quint16 port;

    // 连接但是没有登陆的socket
    QList<QTcpSocket*> unconnList;
    // 登录的用户的socket
    QMap<int, QTcpSocket*> connList;

    TcpServer(QObject *parent = nullptr);
    virtual void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;

    // 统一发送格式化的信息
    inline void _sendMsg(QTcpSocket*, const QString&);
    // 把json格式准备好
    /*
    {"sender":"xxx","quest":"xxx"}
    */
    inline QJsonObject prepareSendJson(const QString&);

    void recvLogin(QString);
    void recvRegister(QString);
    void recvMessage(QString);

private slots:
    // 槽函数，用于接受来信，并按照类别调用不同的函数处理
    void _recvMsg();
    // 客户端断开连接的时候触发这个槽函数，处理客户端异常下线的情况
    void _disconnected();
};

#endif // TCPSERVER_H
