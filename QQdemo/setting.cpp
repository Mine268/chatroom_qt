#include "setting.h"
#include "ui_setting.h"

Setting::Setting(QWidget* parent)
    : FatherWidget(parent)
    , ui(new Ui::Setting)
{
    ui->setupUi(this);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(0, 0); //设置阴影距离
    effect->setColor(QColor(38, 78, 119, 127)); //设置阴影颜色
    effect->setBlurRadius(22); //设置阴影圆角
    ui->frame->setGraphicsEffect(effect);
    //设置关于窗体为圆角
}

Setting::~Setting()
{
    delete ui;
}

void Setting::setSocket(ClientTcpSocket* _clientSocket)
{
    clientSocket = _clientSocket;
    //修改数据
    //ToDo
}

void Setting::setData(QPixmap picture, QString& id, QString& name)
{
    ui->label->setPixmap(picture.scaled(100, 100));
    ui->userid->setText(id);
    ui->userid->setEnabled(false);
    ui->username->setText(name);
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
