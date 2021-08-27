#include "addfriend.h"
#include "ui_addfriend.h"

AddFriend::AddFriend(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::AddFriend)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->lineEdit->setPlaceholderText("请输入Name/Id");
}

AddFriend::~AddFriend()
{
    delete ui;
}

void AddFriend::setSocket(QTcpSocket* _clientSocket)
{
    clientSocket = _clientSocket;
    //ToDo
    //connect( , , , receive_friendlist);
}

void AddFriend::mouseMoveEvent(QMouseEvent* event)
{
    //未开启鼠标奥追踪的情况下，当鼠标按下时才能触发
    if (mouse_is_press) {
        this->move(event->globalPos() - old_pos);
    }
}

void AddFriend::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        mouse_is_press = true;
        old_pos = event->pos();
        return QWidget::mousePressEvent(event);
    }
}

void AddFriend::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    mouse_is_press = false;
}

void AddFriend::on_close_clicked()
{
    //关闭窗口
    this->close();
}

void AddFriend::on_minimize_clicked()
{
    //最小化窗口
    this->showMinimized();
}

void AddFriend::on_maximize_clicked()
{
    //最大化窗口
    this->showMaximized();
}

void AddFriend::on_pushButton_clicked()
{
    //查找好友，需要发送消息
    //ToDo :clientsocket.send*
}

void AddFriend::on_lineEdit_returnPressed()
{
    //回车查找
    on_pushButton_clicked();
}

void AddFriend::receive_friendlist(QList<People>)
{
    //根据返回的列表构建QlistWidget
    //ToDo
}

void AddFriend::close_for_mainWidget()
{
    //主窗口的关闭将所有页面关闭
    this->close();
}
