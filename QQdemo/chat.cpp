#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget* parent)
    : FatherWidget(parent)
    , ui(new Ui::Chat)
{
    ui->setupUi(this);
    oldSize = this->size();

    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose);
}

Chat::~Chat()
{
    delete ui;
}

void Chat::setSocket(QTcpSocket* _clientSocket)
{
    clientSocket = _clientSocket;
}

void Chat::close_for_mainWidget()
{
    //关闭窗口
    this->close();
}

void Chat::on_close_clicked()
{
    //关闭窗口
    this->close();
}

void Chat::on_minimize_clicked()
{
    //最小化窗口
    this->showMinimized();
}

void Chat::on_send_clicked()
{
    //发送内容到用户中
}

void Chat::on_empty_clicked()
{
    //清空输入框中的内容
    ui->MyMsg->clear();
}

void Chat::on_maximize_clicked()
{
    //最大化窗口，然后改变图标
    QSize maxwindowsize = QApplication::desktop()->size();
    QPixmap maxminpic(":/tool/maxmin.png");
    QPixmap maxminpicscaled = maxminpic.scaled(20, 20);
    if (this->size() != maxwindowsize) {
        oldSize = this->size(); //原来的窗口大小
        oldGeometry = this->geometry(); //原来的窗口位置
        ui->maximize->setIcon(QIcon(maxminpicscaled));
        ui->maximize->setIconSize(QSize(20, 20));
        this->setGeometry(0, 0, maxwindowsize.width(), maxwindowsize.height());
    } else {
        this->setGeometry(oldGeometry);
        ui->maximize->setIcon(QIcon(":/tool/maximize.png"));
        ui->maximize->setIconSize(QSize(20, 20));
    }
}