#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::Chat)
{
    ui->setupUi(this);
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
void Chat::mouseMoveEvent(QMouseEvent* event)
{
    //未开启鼠标奥追踪的情况下，当鼠标按下时才能触发
    if (mouse_is_press) {
        this->move(event->globalPos() - old_pos);
    }
}

void Chat::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        mouse_is_press = true;
        old_pos = event->pos();
        return QWidget::mousePressEvent(event);
    }
}

void Chat::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    mouse_is_press = false;
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
