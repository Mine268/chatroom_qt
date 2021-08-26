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
    // 鍗曚緥璁捐妯″紡
    static TcpServer *me;
    // 宸茬粡杩炴帴浣嗘槸娌℃湁鐧诲綍鐨勭敤鎴穝ocket
    QList<QTcpSocket*> unconnList;
    // 宸茬粡鐧诲綍鐨勭敤鎴穝ocket
    QMap<int, QTcpSocket*> connList;

    TcpServer(QObject *parent = nullptr);
    virtual void incomingConnection(qintptr handle) Q_DECL_OVERRIDE;

    void recvLogin(QString);
    void recvRegister(QString);
    void recvMessage(QString);

private slots:
    // 鏀跺埌鏉ヨ嚜瀹㈡埛绔殑娑堟伅锛屾湰鏂规硶浼氶鍏堝垎鏋愭秷鎭睘浜庡摢涓€绫伙紝鐒跺悗璋冪敤涓嶅悓鐨勬柟娉曞鐞    void _recvMsg();
};

#endif // TCPSERVER_H
