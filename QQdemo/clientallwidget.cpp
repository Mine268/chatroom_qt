#include "clientallwidget.h"

clientAllWidget::clientAllWidget(QObject* parent)
    : QObject(parent)
{
    init_socket();
}
void clientAllWidget::start()
{
    logindialog = new loginDialog();
    logindialog->setSocket(clientSocket);
    logindialog->show();
    connect(logindialog, &loginDialog::OkToLogin, this, &clientAllWidget::okToLogin);
}

clientAllWidget::~clientAllWidget()
{
    delete clientSocket;
}

void clientAllWidget::init_socket()
{
    clientSocket = new ClientTcpSocket();
    //接收服务器发送的信息
}

void clientAllWidget::okToLogin(QString _userID, QString _userPwd)
{
    //登录成功，需要将登录框关闭，跳转到主界面
    //ToDo
    userId = _userID;
    userPwd = _userPwd;
    mainWidget = new FriendList(nullptr);
    mainWidget->setdata(userId, userPwd);
    mainWidget->setSocket(clientSocket);
    mainWidget->show();
    connect(mainWidget, &FriendList::closeMainWidget, this, [=]() { clientSocket->disconnect(); });
}
