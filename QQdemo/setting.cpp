#include "setting.h"
#include "ui_setting.h"

Setting::Setting(QWidget* parent)
    : FatherWidget(parent)
    , ui(new Ui::Setting)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose);
}

Setting::~Setting()
{
    delete ui;
}

void Setting::setSocket(ClientTcpSocket* _clientSocket)
{
    clientSocket = _clientSocket;
}

void Setting::close_for_mainWidget()
{
    //关闭窗口
    this->close();
}

void Setting::on_minimize_clicked()
{
    //最小化
    this->showMinimized();
}

void Setting::on_maximize_clicked()
{
    //最大化
    this->showMaximized();
}

void Setting::on_cancel_clicked()
{
    //关闭窗口
    this->close();
}

void Setting::on_sure_clicked()
{
    //修改信息，需要发送消息
    //ToDo
    //connect()
}

void Setting::on_close_clicked()
{
    this->close();
}
