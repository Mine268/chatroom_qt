#include "setting.h"
#include "ui_setting.h"

Setting::Setting(QWidget* parent)
    : QWidget(parent)
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

void Setting::setSocket(QTcpSocket* _clientSocket)
{
    clientSocket = _clientSocket;
}

void Setting::close_for_mainWidget()
{
    //关闭窗口
    this->close();
}

void Setting::mouseMoveEvent(QMouseEvent* event)
{
    //未开启鼠标奥追踪的情况下，当鼠标按下时才能触发
    if (mouse_is_press) {
        this->move(event->globalPos() - old_pos);
    }
}

void Setting::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        mouse_is_press = true;
        old_pos = event->pos();
        return QWidget::mousePressEvent(event);
    }
}

void Setting::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    mouse_is_press = false;
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
