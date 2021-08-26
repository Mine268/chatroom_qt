#include "logindialog.h"
#include "ui_logindialog.h"
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

    ui->pciture->setPixmap(QPixmap::fromImage(
        QImage("C:\\Users\\God\\Desktop\\新建文件夹\\cat-5120x2880-black-yellow-eyes-4k-19934.jpg"))
                               .scaled(131, 111));
    //    this->setWindowFlags(Qt::SplashScreen);
    setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose);

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
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->start();
}

void loginDialog::setSocket()
{
    clientSocket = new QTcpSocket();
    clientSocket->connectToHost("127.0.0.1", 5530);
    if (!clientSocket->waitForConnected(3000)) {
        QMessageBox::information(this, "QT网络通信", "连接服务端失败！");
        return;
    }
    //    qDebug() << "Client: " << clientSocket->localAddress() << mp_clientSocket->localPort() << mp_clientSocket->socketDescriptor();
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(ClientRecvData()));
    //接收服务器发送的信息
}

void loginDialog::ClientRecvData()
{
    //将接收内容存储到字符串中
    QByteArray content = clientSocket->readAll();
    QString content_ = content;
    if (content.length() == 0) {
        QMessageBox::information(this, "QT网络通信", "接收服务端数据失败！");
        return;
    }
    if (content_ == "OK") {
    }
}
loginDialog::~loginDialog()
{
    delete ui;
}
void loginDialog::mouseMoveEvent(QMouseEvent* event)
{
    //未开启鼠标奥追踪的情况下，当鼠标按下时才能触发
    if (mouse_is_press) {
        this->move(event->globalPos() - old_pos);
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
}
