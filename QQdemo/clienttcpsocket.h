#ifndef CLIENTTCPSOCKET_H
#define CLIENTTCPSOCKET_H

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QList>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

struct user {
    QString id;
    QString name;
};

struct chat_msg {
    QString from_id;
    QString to_id;
    QString time;
    QString value; //消息内容
};

class ClientTcpSocket : public QObject {
    Q_OBJECT
public:
    ClientTcpSocket(QObject* parent = nullptr);
    void sendloginMsg(const QString& username, const QString& pwd);
    void sendRegMsg(const QString& username, const QString& pwd);
    void sendMsgTo(const QString& from_id, const QString& to_id, const QString& time,
        const QString& msg);
    void sendFriendAdd(const QString& id);
    void sendFriendDel(const QString& id);
    QJsonObject client_prepareSendJson(const QString& quest);

signals:
    void recvLoginConMsg(const QString msg);
    void recvLoginDeMsg(const QString msg);
    void recvRegConMsg(const QString msg);
    void recvRegDeMeg(const QString msg);
    void recvFriendList(QList<struct user> list);
    void recvChatMsg(struct chat_msg chatmsg);

private slots:
    void _recvMsg();

private:
    QTcpSocket* clientSocket;
    void initialLize();
};

#endif // CLIENTTCPSOCKET_H
