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

    ui->label->setVisible(false);
    ui->label_2->setVisible(false);
    ui->label_3->setVisible(false);
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
        //未完成
        qDebug() << "注册失败";
        if (username.isEmpty()) {
            ui->label->setVisible(true);
            ui->label->setStyleSheet(warning_background_2);
        }
        if (passward.compare(passward_re) != 0) {
            ui->label_3->setVisible(true);
            ui->label_3->setStyleSheet(warning_background_2);
        }
    }
}

void signinDialog::receiveRgMsg(QString)
{
    //处理接受到的注册内容
    //如果注册成功，发送信号给登录窗口： emit okToRegister(QString)
    //如果注册失败，提示错误消息： QMessage::information / 直接在框中提示
    //ToDo
    //未完成
    QString txt;
    if (true) {
        txt = "注册成功<br>你的id是：<br>";
        //        txt += userid;
        QMessageBox::information(NULL, "Title", txt, QMessageBox::Ok, QMessageBox::Ok);
    } else {
        txt = "注册失败<br>请重新注册";
        QMessageBox::information(NULL, "Title", txt, QMessageBox::Ok, QMessageBox::Ok);
    }
}

//新添加

void signinDialog::on_username_textEdited(const QString& arg1)
{
    if (ui->username->text() == "") {
        ui->label->setVisible(true);
        ui->label->setStyleSheet(warning_background_1);
    } else {
        ui->label->setVisible(false);
    }
}

void signinDialog::on_passward_r_textEdited(const QString& arg1)
{

    QString passward = ui->passward->text();
    QString passward_re = ui->passward_r->text();
    if (passward.compare(passward_re) != 0) {
        ui->label_3->setVisible(true);
        ui->label_3->setStyleSheet(warning_background_1);
    } else {
        ui->label_3->setVisible(false);
    }
}

void signinDialog::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 2) {
        qDebug() << "被选中";
        ui->passward->setEchoMode(QLineEdit::Normal);
        ui->passward_r->setEchoMode(QLineEdit::Normal);
    } else if (arg1 == 0) {
        qDebug() << "未被选中";
        ui->passward->setEchoMode(QLineEdit::Password);
        ui->passward_r->setEchoMode(QLineEdit::Password);
    }
}
