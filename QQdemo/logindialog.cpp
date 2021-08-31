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

    //构造函数void loginDialog::init_ui()末尾加入即可
    ReadInit("usernumber", idList);
    ReadInit("userpassward", pwdList);

    /*
     *
     *
     * Debug
     *
     * */
    qDebug() << idList;

    ui->usernumber->addItems(idList);
    connect(ui->usernumber, SIGNAL(currentTextChanged(QString)), this, SLOT(loadpwd(QString)));
    connect(ui->usernumber, SIGNAL(currentIndexChanged(int)), this, SLOT(loadpwd(int)));

    if (ui->usernumber->count() != 0)
        loadpwd(0);
}
void loginDialog::init_ui()
{
    ui->setupUi(this);
    setWindowTitle("登录");
    setWindowIcon(QIcon("C:\\Users\\God\\Desktop\\新建文件夹\\聊天.png"));

    setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose);

    QString style = "border-radius: 65px;border:0px white;background: green";
    ui->picture->setStyleSheet(style);
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

    /*
     * 设置提示文字
     * */

    usernumberinput = new QLineEdit(this);
    ui->usernumber->setLineEdit(usernumberinput);
    usernumberinput->setPlaceholderText("ID");
    ui->userpassward->setPlaceholderText("密码");

    /*
     *
     * 淡入淡出
     * */
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

void loginDialog::WriteInit(QString key, QStringList value)
{
    qDebug() << "write";
    QString path = "./login.ini";
    //创建配置文件操作对象
    QSettings* config = new QSettings(path, QSettings::IniFormat);
    QVariant variant;
    variant.setValue(value);
    //将信息写入配置文件
    config->beginGroup("config");
    config->setValue(key, variant);
    config->endGroup();
    delete config;
}

void loginDialog::ReadInit(QString key, QStringList& value)
{
    //    value.clear();
    QString path = "./login.ini";
    //创建配置文件操作对象
    QSettings* config = new QSettings(path, QSettings::IniFormat);
    //读取配置信息
    QVariant variant = config->value(QString("config/") + key);
    value = variant.value<QStringList>();
}

loginDialog::~loginDialog()
{
    delete ui;
}
void loginDialog::mouseMoveEvent(QMouseEvent* event)
{
    //未开启鼠标奥追踪的情况下，当鼠标按下时才能触发
    if (mouse_is_press) {
        if (event->x() >= 25 && event->x() <= 196 && event->y() >= 7 && event->y() <= 28)
            return;
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
    //记住密码功能

    //检测是否已存在该用户
    userId = usernumberinput->text();
    userPwd = ui->userpassward->text();

    bool is_exist = false;
    int idx = -1;
    for (int i = 0; i < idList.size(); i++) {
        if (idList[i] == userId) {
            qDebug() << idList[i] << userId;

            is_exist = true;
            idx = i;
            break;
        }
    }
    qDebug() << is_exist;
    if (ui->remember->isChecked()) //记住密码
    {
        if (!is_remember) //之前未记住密码，加入密码
        {
            qDebug() << "未记住密码->记住密码";
            if (is_exist) //用户已存在
            {
                pwdList[idx] = userPwd;
            } else //用户不存在
            {
                qDebug() << "新用户，记住";
                idList.push_front(userId);
                pwdList.push_front(userPwd);
            }
            qDebug() << idList;
            WriteInit("usernumber", idList);
            WriteInit("userpassward", pwdList);
        }
        //else 已记住密码，不需要更新本地用户密码
    } else //不记住密码
    {
        if (is_remember) //之前记住了(肯定是存在的用户)，密码设为空
        {
            qDebug() << "记住密码->不记住密码";
            pwdList[idx] = "";
            WriteInit("usernumber", idList);
            WriteInit("userpassward", pwdList);
        } else //之前没记住
        {
            if (!is_exist) //用户不存在
            {
                qDebug() << "新用户，不记住";
                idList.push_front(userId);
                pwdList.push_front("");
                WriteInit("usernumber", idList);
                WriteInit("userpassward", pwdList);
            }
            // 已存在但不记住密码，不需要更新本地用户密码
        }
    }

    clientSocket->sendloginMsg(userId, userPwd);
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
    //    showFailMessgae.setInterval(10000);
    //    showFailMessgae.start();
    usernumberinput->setPlaceholderText(failMessage);
    //    showFailMessgae.stop();
    //    usernumberinput->setPlaceholderText("ID");
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

void loginDialog::on_remember_clicked(bool checked)
{
    if (checked) {
        need_remember = true;
    } else {
        need_remember = false;
    }
}

void loginDialog::loadpwd(QString str)
{
    qDebug() << str;
    is_remember = false;
    for (int i = 0; i < idList.size(); i++) {
        if (idList[i] == str) {
            ui->userpassward->setText(pwdList[i]);
            if (pwdList[i] != "") {
                is_remember = true;
                ui->remember->setCheckState(Qt::Checked);
            }
            return;
        }
    }
    ui->userpassward->setText("");
}

void loginDialog::loadpwd(int i)
{
    qDebug() << i;
    ui->userpassward->setText(pwdList[i]);
    if (pwdList[i] != "") {
        is_remember = true;
        ui->remember->setCheckState(Qt::Checked);
    }
}

void loginDialog::close_ani()
{
    qDebug() << "close_ani";
    disappear_ani = new QPropertyAnimation(this, "geometry");
    disappear_ani->setTargetObject(ui->frame);
    disappear_ani->setDuration(2000);
    disappear_ani->setStartValue(QRect(ui->frame->pos().x(), ui->frame->pos().y(), ui->frame->width(), ui->frame->height()));
    disappear_ani->setEndValue(QRect(ui->frame->pos().x() + this->width() + 50,
        ui->frame->pos().y(), ui->frame->width(), ui->frame->height())); //移动
    //    disappear_ani->setEndValue(QRect(ui->frame->pos().x(), ui->frame->pos().y(), 0, ui->frame->height()));//缩小width
    disappear_ani->start();

    connect(disappear_ani, SIGNAL(finished()), this, SLOT(close_widget()));
    qDebug() << "end";
}
