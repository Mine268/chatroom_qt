#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include "tcpserver.h"
#include "datadb.h"

#include <QObject>
#include <QMap>
#include <QImage>

class ServerManager : public QObject
{
    Q_OBJECT
public:
    explicit ServerManager(QObject *parent = nullptr);
    ~ServerManager();

    void configure(QHostAddress _serverHost     // 服务器地址
                   , short _serverPort          // 服务器监听接口
                   , const QString &_dbDriver   // 数据库驱动
                   , const QString &_dbName     // 数据库名称
                   , const QString &_dbHost		// 设置数据库主机地址
                   , const short   &_dbPort		// 设置数据库主机端口
                   , const QString &_dbUsr		// 设置数据库登录名称
                   , const QString &_dbPwd		// 设置数据库登录密码
                   );
    void start();

private:
    TcpServer *tcpserver;
    DataDB *db;

    // 用于配置服务器和数据库的参数
    QHostAddress serverHost;
    short serverPort;
    QString dbDriver;
    QString dbName;
    QString dbHost;
    short dbPort;
    QString dbUsr;
    QString dbPwd;

    // 已经登录的用户列表
    QMap<qint64, QTcpSocket*> loginUsers;
    // 反转表，用于反查，因为id和socket都是唯一的所以可以这么搞
    QMap<QTcpSocket*, qint64> r_loginUsers;

    // 发送未读消息
    void sendHangedMsg(const qint64 _id);
    QImage StringToQImage(const QString&);

signals:

private slots:
    // 分别对应TcpServer中的signals
    void getLogin(QTcpSocket*, const QString&, const QString&);
    void getRegister(QTcpSocket*, const QString&, const QString&);
    void getMessage(const QString&, const QString&, const QString&, const QString&);
    void getImage(const QString&, const QString&, const QString&, const QString&);
    void getFriendAddQuest(const QString&, const QString&);
    void getUserQueryQuest(const qint64,const qint64);
    void getFriendDelQuest(const QString&, const QString&);
    // 收到好友列表的请求
    void getFriendListQuest(const QString&);
    // 收到发送未读消息的请求
    void getPullHangedMsg(const qint64);
    // 有人异常掉线了，需要从表中删除那个人
    void getUserDropEx(QTcpSocket*);

};

#endif // SERVERMANAGER_H
