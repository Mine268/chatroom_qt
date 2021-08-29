#ifndef CLIENTALLWIDGET_H
#define CLIENTALLWIDGET_H

#include "clienttcpsocket.h"
#include "friendlist.h"
#include "logindialog.h"
#include "signindialog.h"
#include <QMessageBox>
#include <QObject>

/*
 *  管理各个界面的跳转与socket的发送与设置
 *
 * */

class clientAllWidget : public QObject {
    Q_OBJECT
public:
    explicit clientAllWidget(QObject* parent = nullptr);
    void start();

private:
    void init_socket();

public slots:
    void okToLogin();

private:
    QTcpSocket* clientSocket;
    loginDialog* logindialog;
    signinDialog* signindialog;
    FriendList* mainWidget;
};

#endif // CLIENTALLWIDGET_H
