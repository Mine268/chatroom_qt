#include "signindialog.h"
#include "ui_signindialog.h"

#include <QPropertyAnimation>

signinDialog::signinDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::signinDialog)
{
    init_ui();
}

void signinDialog::init_ui()
{
    ui->setupUi(this);
    setWindowTitle("注册");
    setWindowIcon(QIcon("C:\\Users\\God\\Desktop\\新建文件夹\\注册.png"));

    setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(0, 0); //设置阴影距离
    effect->setColor(QColor(38, 78, 119, 127)); //设置阴影颜色
    effect->setBlurRadius(22); //设置阴影圆角
    ui->frame->setGraphicsEffect(effect);

    ui->username->setPlaceholderText("用户名");
    ui->passward->setPlaceholderText("密码");
    ui->passward_r->setPlaceholderText("重复密码");
}
signinDialog::~signinDialog()
{
    delete ui;
}

void signinDialog::setSocket(QTcpSocket* _socket)
{
    ClientSocket = _socket;
    //ToDo
    //connect() 注册是否成功的消息
    //connect()
}

void signinDialog::mouseMoveEvent(QMouseEvent* event)
{
    //未开启鼠标奥追踪的情况下，当鼠标按下时才能触发
    if (mouse_is_press) {
        this->move(event->globalPos() - old_pos);
    }
}

void signinDialog::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        mouse_is_press = true;
        old_pos = event->globalPos() - pos();
        return QDialog::mousePressEvent(event);
    }
}

void signinDialog::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    mouse_is_press = false;
}

void signinDialog::on_cancel_clicked()
{
    //发送信号给登录窗口
    //关闭注册框后会显示登录框
    emit closeDialog();
    this->close();
}

void signinDialog::on_sure_clicked()
{
    //发送注册消息
    QString username = ui->username->text();
    QString passward = ui->passward->text();
    QString passward_re = ui->passward_r->text();
    if (passward.compare(passward_re) == 0 && !username.isEmpty()) {
        //socket.send

        //Test code
        qDebug() << "注册成功";
        emit okToRegister(username);
        this->close();
    } else {
        //提示密码重复错误
        //ToDo
    }
}

void signinDialog::receiveRgMsg(QString)
{
    //处理接受到的注册内容
    //如果注册成功，发送信号给登录窗口： emit okToRegister(QString)
    //如果注册失败，提示错误消息： QMessage::information / 直接在框中提示
    //ToDo
}
