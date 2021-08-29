#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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

void MainWindow::on_pushButton_start_server_clicked()
{
    int port = 0;
    port = ui->lineEdit_port->text().toInt();
    QHostAddress ip(ui->lineEdit_ip->text());
    if(port == 0 || ip.isNull()){
        QMessageBox::warning(NULL,"warning","ip and port cannot be empty!");
    }else{
        server->configure(ip, port);
        server->start();

        // 连接信号函数和槽函数
        connect(server, &TcpServer::recvLogin, this, &MainWindow::getLogin);
        connect(server, &TcpServer::recvRegister, this, &MainWindow::getRegister);
        connect(server, &TcpServer::recvMessage, this, &MainWindow::getMessage);
        connect(server, &TcpServer::recvFriendAddQuest, this, &MainWindow::getFriendAddQuest);
        connect(server, &TcpServer::recvFriendDelQuest, this, &MainWindow::getFriendDelQuest);
    }
    ui->pushButton_start_server->setEnabled(false);
    ui->pushButton_shutdown_server->setEnabled(true);
}

void MainWindow::getLogin(QTcpSocket *_skt, const QString &_usr, const QString &_pwd)
{
    qDebug() << "[login msg]:" << _skt << ',' << _usr << ',' << _pwd;
}

void MainWindow::getRegister(QTcpSocket *_skt, const QString &_usr, const QString &_pwd)
{
    qDebug() << "[register msg]:" << _skt << ',' << _usr << ',' << _pwd;
}
void MainWindow::getMessage(const QString &_from, const QString &_to
                            , const QString &_date, const QString &_msg)
{
    qDebug() << "[send message]:" << _from << _to << _date << _msg;
}
void MainWindow::getFriendAddQuest(const QString &_master, const QString &_guest)
{
    qDebug() << "[add friend]:" << _master << _guest;
}
void MainWindow::getFriendDelQuest(const QString &_master, const QString &_guest)
{
    qDebug() << "[del friend]:" << _master << _guest;
}

void MainWindow::on_pushButton_shutdown_server_clicked()
{
    server->close();
    ui->pushButton_start_server->setEnabled(true);
    ui->pushButton_shutdown_server->setEnabled(false);
}
