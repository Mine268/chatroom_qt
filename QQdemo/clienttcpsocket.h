#ifndef CLIENTTCPSOCKET_H
#define CLIENTTCPSOCKET_H

#include <QCryptographicHash>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QList>
#include <QMessageBox>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
struct user {
    QString id;
    QString name;
    QString email;
    bool online;
    bool isfriend;
};
Q_DECLARE_METATYPE(user);
Q_DECLARE_METATYPE(user*);

struct chat_msg {
    QString from_id;
    QString to_id;
    QString time;
    QString value; //消息内容
};
Q_DECLARE_METATYPE(chat_msg);

class ClientTcpSocket : public QObject {
    Q_OBJECT

public:
    QString getlocal();

    ClientTcpSocket(QObject* parent = nullptr);
    ~ClientTcpSocket();
    void sendloginMsg(const QString& username, const QString& pwd);
    void sendRegMsg(const QString& username, const QString& pwd);
    void sendMsgTo(QString from_id, QString to_id, QString time, QString msg);
    void sendFriendAdd(const QString& me_id, const QString& you_id);
    void sendFriendDel(const QString& me_id, const QString& you_id);
    void searchUser(const QString& me_id, const QString& you_id);
    void sendFriendList(const QString& id);
    //    void sendImage();
    void pullMessage(const QString& id);

    /*
     * 添加好友请求
     * */
    void friendAddQuset(QString& queryid, QString& senderid);
    void friendAgree(QString& friendid, QString& hostid, QString& name, QString& email);
    void friendDisagree(QString& id);

    QJsonObject client_prepareSendJson(const QString& quest);

    void write_wait(QByteArray);

    void modifyinfo(QString& id, QString& newname);
signals:

    /*
     * 添加好友请求
     * */
    void recvAddAccept(struct user);
    void recvAddFriendQuset(QString);
    void recvAddDeny();

    void recvLoginConMsg(const QString msg);
    void recvLoginDeMsg(const QString msg);
    void recvRegConMsg(const QString msg);
    void recvRegDeMeg(const QString msg);
    void recvFriendList(QList<struct user> list);
    void recvChatMsg(struct chat_msg chatmsg);
    void recvUserInfo(struct user userinfo);

    //    void recvFriendAccept();

private slots:
    void _recvMsg();

private:
    QString data_md5(QString);
    QTcpSocket* clientSocket;
    void initialLize();
};

#endif // CLIENTTCPSOCKET_H