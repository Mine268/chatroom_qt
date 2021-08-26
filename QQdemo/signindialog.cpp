#include "signindialog.h"
#include "ui_signindialog.h"

#include <QPropertyAnimation>

signinDialog::signinDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::signinDialog)
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
    QPropertyAnimation* animation = new QPropertyAnimation(ui->frame, "pos");
    animation->setDuration(1000);
    animation->setStartValue(QPoint());
    //    animation->setDirection(QAbstractAnimation::Direction::Forward);
    animation->setEndValue(QPoint(ui->frame->width(), 0));
    animation->start();
    qDebug() << pos();
    this->close();
}
