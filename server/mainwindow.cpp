#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setGeometry(0, 0, 700, 600);

    this->startTimer(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startSrv_clicked()
{
    // 检查端口是否正确
    if (isDigitString(ui->serverPort->text())) {
        auto port = ui->serverPort->text().toUInt();
        if (port > 65535) {
            QMessageBox::information(this, "错误", "端口号必须小于65536且大于0。");
            return;
        }

        srm.configure(QHostAddress::Any,
                      port,
                      ui->dbDriver->text(),
                      ui->dbName->text(),
                      ui->dbIP->text(),
                      ui->dbPort->text().toUInt(),
                      ui->dbUsr->text(),
                      ui->dbPwd->text());

        auto isStarted = srm.start();

        if (!isStarted) {
            QMessageBox::information(this, "错误", "无法连接到数据库或服务器。");
            srm.close();
            return;
        }

        ui->startSrv->setEnabled(false);
        ui->closeSrv->setEnabled(true);

    } else {
        QMessageBox::information(this, "错误", "端口号必须是正整数且小于65536。");
        return;
    }
}

bool MainWindow::isDigitString(const QString& src) {
    const char *s = src.toUtf8().data();
    while(*s && *s>='0' && *s<='9')s++;
    return !bool(*s);
}

void MainWindow::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    auto usrList = srm.getUserList();
    auto size = usrList.size();

    ui->onlineCount->setText(QString::number(size));
    ui->onlineTable->clearContents();
    ui->onlineTable->setRowCount(size);
    int row = 0;
    for (auto it = usrList.begin(); it != usrList.end(); ++it, ++row) {
        ui->onlineTable->setItem(row, 0
                                 , new QTableWidgetItem(QString::number(it.key())));
    }
}

void MainWindow::on_closeSrv_clicked()
{
    srm.close();
    ui->startSrv->setEnabled(true);
    ui->closeSrv->setEnabled(false);
}



