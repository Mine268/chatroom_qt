#include "clientallwidget.h"

clientAllWidget::clientAllWidget(QObject* parent)
    : QObject(parent)
{
    //    init_socket();
}

void clientAllWidget::start()
{
    logindialog = new loginDialog();
    logindialog->setSocket(clientSocket);
    logindialog->show();
    connect(logindialog, &loginDialog::OkToLogin, this, &clientAllWidget::okToLogin);
}

void clientAllWidget::init_socket()
{
    clientSocket = new QTcpSocket();
    clientSocket->connectToHost("127.0.0.1", 5530);
    if (!clientSocket->waitForConnected(3000)) {
        QMessageBox::information(nullptr, "QT网络通信", "连接服务端失败！");
        return;
    }
    //    qDebug() << "Client: " << clientSocket->localAddress() << mp_clientSocket->localPort() << mp_clientSocket->socketDescriptor();
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(ClientRecvData()));
    //接收服务器发送的信息
}

void clientAllWidget::okToLogin()
{
    //登录成功，需要将登录框关闭，跳转到主界面
    //ToDo
    mainWidget = new FriendList(nullptr);
    mainWidget->show();
    //    mainWidget->setSocket(clientSocket);
}
