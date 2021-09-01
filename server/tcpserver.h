#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>

#include "datadb.h"

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    // 设置服务器监听
    void configure(QHostAddress, quint16);
    // 服务器开始监听
    bool start();

    void sendLoginConfirm(QTcpSocket*);
    void sendLoginDeny(QTcpSocket*, const QString&);
    void sendRegConfirm(QTcpSocket*, const QString&);
    void sendRegDeny(QTcpSocket*, const QString&);
    void sendFriendList(QTcpSocket*, const QList<std::tuple<QString, QString, bool>>&);

    // 向被添加好友的人发送好友确认
    void sendFrdAddQuest(QTcpSocket*, const qint64 sender, const qint64 query);
    // 向要添加好友的人发送是否被允许添加为好友
    void sendFriendAddAc(QTcpSocket*
                          , const qint64 id, const QString &name, const QString &email);
    void sendFriendAddDeny(QTcpSocket*);

    void sendChatMsg(QTcpSocket*, const QList<DataDB::msgInfo>&);
    void sendChatImg(QTcpSocket*, const QString&, const QString&
                     , const QString&, const QString&);
    void sendUserInfo(QTcpSocket*, const qint64, const QString&, const QString&);

    static TcpServer *getInstance();
    static void releaseInstance();

private:
    // 单例设计模式
    static TcpServer *me;
    // 服务器地址
    QHostAddress addr;
    // 监听端口
    quint16 port;

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
    void recvFriendDelQuest(const QString&, const QString&);
    void recvFriendListQuest(const QString&);
    // 如果收到了好友申请
    void recvFriendAddQuest(const QString&, const QString&);
    // 如果某人拒绝了好友申请
    void recvFriendAddDisgree(const qint64);
    // 如果某人接受了好友申请
    void recvFriendAddAgree(const qint64, const qint64, const QString&, const QString&);
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
