#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server = TcpServer::getInstance();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QList<QPair<QString, QString>> list = {
        {"7355608", "CT"},
        {"1738448", "Cat"},
        {"000000", "Bear"}
    };

    server->sendLoginConfirm(nullptr);
    server->sendLoginDeny(nullptr, "No such user");
    server->sendRegConfirm(nullptr, "114514");
    server->sendRegDeny(nullptr, "Bad password");
    server->sendFriendList(nullptr, list);
    server->sendChatMsg(nullptr, "114514", "1919810", "2020-1-1", "hello, world");
}

