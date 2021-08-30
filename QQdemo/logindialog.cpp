#include "logindialog.h"
#include "ui_logindialog.h"
#include <QBitmap>
#include <QGraphicsDropShadowEffect>
#include <QPainter>
#include <QPropertyAnimation>
#include <QStyleOption>

loginDialog::loginDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::loginDialog)
{
    init_ui();
}
void loginDialog::init_ui()
{
    ui->setupUi(this);
    setWindowTitle("登录");
    setWindowIcon(QIcon("C:\\Users\\God\\Desktop\\新建文件夹\\聊天.png"));

    //    this->setWindowFlags(Qt::SplashScreen);
    setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose);

    QString style = "border-radius: 65px;border:0px white;background: green";
    ui->picture->setStyleSheet(style);
    //    ui->picture->setPixmap(QPixmap::fromImage(
    //        QImage("C:\\Users\\God\\Desktop\\新建文件夹\\cat-5120x2880-black-yellow-eyes-4k-19934.jpg"))
    //                               .scaled(130, 130));

    QPixmap src = QPixmap::fromImage(
        QImage("C:\\Users\\God\\Desktop\\新建文件夹\\cat-5120x2880-black-yellow-eyes-4k-19934.jpg"));
    QSize size(130, 130);
    QBitmap mask(size);
    QPainter painter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.fillRect(0, 0, 130, 130, Qt::white);
    painter.setBrush(QColor(0, 0, 0));
    painter.drawRoundedRect(0, 0, 130, 130, 99, 99);
    QPixmap image = src.scaled(size);
    image.setMask(mask);
    ui->picture->setPixmap(image);

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(0, 0); //设置阴影距离
    effect->setColor(QColor(38, 78, 119, 127)); //设置阴影颜色
    effect->setBlurRadius(22); //设置阴影圆角
    ui->frame->setGraphicsEffect(effect);

    usernumberinput = new QLineEdit(this);
    ui->usernumber->setLineEdit(usernumberinput);
    usernumberinput->setPlaceholderText("ID");
    ui->userpassward->setPlaceholderText("密码");

    QPropertyAnimation* animation = new QPropertyAnimation(this, "windowOpacity");
    animation->setDuration(100);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
}

void loginDialog::setSocket(ClientTcpSocket* _socket)
{
    clientSocket = _socket;
    connect(clientSocket, &ClientTcpSocket::recvLoginConMsg, this, &loginDialog::receive_loginOk_message); //登录成功消息
    connect(clientSocket, &ClientTcpSocket::recvLoginDeMsg, this, &loginDialog::receive_loginFail_message); //登录失败消息
}

loginDialog::~loginDialog()
{
    delete ui;
}
void loginDialog::mouseMoveEvent(QMouseEvent* event)
{
    //未开启鼠标奥追踪的情况下，当鼠标按下时才能触发
    if (mouse_is_press) {
        this->move(event->pos() + pos() - old_pos);
    }
}

void loginDialog::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        mouse_is_press = true;
        old_pos = event->pos();
        return QDialog::mousePressEvent(event);
    }
}

void loginDialog::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    mouse_is_press = false;
}

void loginDialog::on_login_clicked()
{
    //检测是否有此账号
    //发送消息 : socket.send*()
    //连接信号与槽:  connect( , , , receive_login_message(QString))
    userId = usernumberinput->text();
    userPwd = ui->userpassward->text();
    clientSocket->sendloginMsg(userId, userPwd);

    //    //TestCode
    //    qDebug() << "登录";
    //    emit OkToLogin(userId, userPwd);
}

void loginDialog::on_regestor_clicked()
{
    //注册账号
    //新建注册框
    this->hide();
    signindialog = new signinDialog();
    signindialog->setSocket(clientSocket);
    signindialog->show();
    connect(signindialog, &signinDialog::okToRegister, this, &loginDialog::receive_register_message);
    connect(signindialog, &signinDialog::closeDialog, this, &loginDialog::showDialog);
}

void loginDialog::on_cancel_clicked()
{
    //取消，直接关闭窗口
    this->close();
}

void loginDialog::receive_loginOk_message(QString)
{
    //处理发送过来的登录信息，如果成功，发送信号给clientAllWidget :emit(okToLogin)
    this->close();
    emit OkToLogin(userId, userPwd);
}

void loginDialog::receive_register_message(QString _userId)
{
    //将注册成功得到的ID填充至输入框中
    usernumberinput->setText(_userId);
    this->show();
}

void loginDialog::receive_loginFail_message(QString failMessage)
{
    //登录失败，给出提示消息
    //可能是密码错误/连接错误
    //定时显示错误信息
    qDebug() << failMessage;
    QTimer showFailMessgae;
    showFailMessgae.setInterval(1000);
    showFailMessgae.start();
    usernumberinput->setPlaceholderText(failMessage);
    showFailMessgae.stop();
    usernumberinput->setPlaceholderText("ID");
}

void loginDialog::showDialog()
{
    this->show();
}

void loginDialog::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == 2) {
        ui->userpassward->setEchoMode(QLineEdit::Normal);
    } else if (arg1 == 0) {
        ui->userpassward->setEchoMode(QLineEdit::Password);
    }
}
