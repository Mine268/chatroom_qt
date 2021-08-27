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
    int port =0;
    port = ui->lineEdit_port->text().toInt();
    QHostAddress ip(ui->lineEdit_ip->text());
    if(port == 0 || ip.isNull()){
        QMessageBox::warning(NULL,"warning","ip and port cannot be empty!");
    }else{
        server->initiate(ip,port);
        server->start();
    }

}
