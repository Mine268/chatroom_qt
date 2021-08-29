#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    // 设置服务器监听
    void configure(QHostAddress, quint16);
    // 服务器开始监听
    void start();

    void sendLoginConfirm(QTcpSocket*);
    void sendLoginDeny(QTcpSocket*, const QString&);
    void sendRegConfirm(QTcpSocket*, const QString&);
    void sendRegDeny(QTcpSocket*, const QString&);
    void sendFriendList(QTcpSocket*, const QList<std::tuple<QString, QString, bool>>&);
    void sendChatMsg(QTcpSocket*, const QString&, const QString&
                     , const QString&, const QString&);
    void sendChatImg(QTcpSocket*, const QString&, const QString&
                     , const QString&, const QString&);
    void sendUserInfo(QTcpSocket*, const QString&, const QString&);

    static TcpServer *getInstance();
    static void releaseInstance();

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
    ~TcpServer();
    virtual void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;

    // 统一发送格式化的信息
    inline void _sendMsg(QTcpSocket*, const QString&);
    // 把json格式准备好
    /*
    {"sender":"xxx","quest":"xxx"}
    */
    inline QJsonObject prepareSendJson(const QString&);

signals:
    // 这两个需要QTcpSocket*参数是因为未登录/注册的时候不能通过id查找socket
    void recvLogin(QTcpSocket*, const QString&, const QString&);
    void recvRegister(QTcpSocket*, const QString&, const QString&);
    void recvMessage(const QString&, const QString&, const QString&, const QString&);
    void recvFriendAddQuest(const QString&, const QString&);
    void recvFriendDelQuest(const QString&, const QString&);
    void recvFriendListQuest(const QString&);
    void recvImage(const QString&, const QString&, const QString&, const QString&);
    void recvUserQuery(const qint64,const qint64);
    void recvPullHangedMsg(const qint64);
    // 客户端异常下线
    void usrDisconnectedEx(QTcpSocket*);

private slots:
    // 槽函数，用于接受来信，并按照类别调用不同的函数处理
    void _recvMsg();
    // 客户端断开连接的时候触发这个槽函数，处理客户端异常下线的情况
    // 现在好像没法做qaq
    void _disconnected();

signals:
    //用于和mainwindow通信的信号函数，仅用作调试
    void debug_displayMsg();
};

#endif // TCPSERVER_H
