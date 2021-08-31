#include "chat.h"
#include "ui_chat.h"

#include <QBitmap>
#include <QPainter>

Chat::Chat(QWidget* parent)
    : FatherWidget(parent)
    , ui(new Ui::Chat)
{
    ui->setupUi(this);
    oldSize = this->size();

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(0, 0); //设置阴影距离
    effect->setColor(QColor(38, 78, 119, 127)); //设置阴影颜色
    effect->setBlurRadius(20); //设置阴影圆角
    ui->frame->setGraphicsEffect(effect);

    emo = new EmotionWidget(this);
    emo->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    connect(emo, &EmotionWidget::sendgifpath, this, &Chat::add_gif);

    label = new QLabel();
    timer = new QTimer();
    label->setStyleSheet("background-color: rgb(255, 255, 255); border-width: 1px;border-style: solid;border-color: rgb(0, 0, 0); padding: 10px 5px");
    label->setText("发送内容不能为空");
    label->setScaledContents(true);
    label->resize(160, 40);
    label->setAlignment(Qt::AlignVCenter);
    label->setWindowFlags(Qt::FramelessWindowHint);
    label->hide();
    connect(timer, SIGNAL(timeout()), this, SLOT(hidelabel()));
}

Chat::~Chat()
{
    delete ui;
}
void Chat::hidelabel()
{
    label->hide();
    timer->stop();
}
void Chat::setSocket(ClientTcpSocket* _clientSocket)
{
    clientSocket = _clientSocket;
}

void Chat::setInfo(QString my_id, QString your_id, QString myname, QString friendname)
{
    from_id = my_id;
    to_id = your_id;
    username = friendname;
    username_me = myname;
    ui->id->setText(to_id);
    ui->name->setText(username);
    ui->picture->setPixmap(data(username).scaled(65, 65));
}

void Chat::close_for_mainWidget()
{
    //关闭窗口
    this->close();
}

void Chat::on_close_clicked()
{
    //关闭窗口
    emit closeChat(to_id);
    label->close();
    this->close();
}

void Chat::on_minimize_clicked()
{
    //最小化窗口
    this->showMinimized();
}

void Chat::on_send_clicked()
{

    QDateTime dateTime(QDateTime::currentDateTime());
    QString qStr = dateTime.toString("yyyy-MM-dd hh:mm");

    if (ui->MyMsg->toPlainText().isEmpty()) {
        QPoint send_point = ui->send->pos();
        send_point = this->mapToGlobal(send_point);
        label->move(send_point.x() + ui->send->width() / 2 - label->width() / 2,
            send_point.y() + this->height() - 70);
        label->show();
        label->raise();
        timer->start(3000); //停留3秒
        return;
    }

    qDebug() << "SendMessage: " << from_id << " " << to_id << " ";

    QString chat_msg = ui->MyMsg->toHtml();
    ui->MyMsg->clear();

    ui->contents->setItemAlignment(Qt::AlignLeft);
    clientSocket->sendMsgTo(from_id, to_id, qStr, chat_msg);
    QListWidgetItem* Item = new QListWidgetItem;

    showMessage* show = new showMessage(this);
    show->setinfo(from_id, qStr, chat_msg);
    //    Item->setText();

    show->show();
    ui->contents->addItem(Item);
    Item->setSizeHint(show->size());
    ui->contents->setItemWidget(Item, show);
    ui->contents->setCurrentItem(Item);
    //发送内容到用户中
}

void Chat::on_empty_clicked()
{
    //清空输入框中的内容
    ui->MyMsg->clear();
}

void Chat::chat_msg_display(struct chat_msg chatmsg)
{

    QListWidgetItem* aItem = new QListWidgetItem();
    QString send_msg = "发送方: " + username + " " + chatmsg.time + "\n" + chatmsg.value;
    aItem->setText(send_msg);
    ui->contents->addItem(aItem);
    ui->contents->setCurrentItem(aItem);
}

void Chat::on_maximize_clicked()
{
    //最大化窗口，然后改变图标
    QSize maxwindowsize = QApplication::desktop()->size();
    QPixmap maxminpic(":/tool/maxmin.png");
    QPixmap maxminpicscaled = maxminpic.scaled(20, 20);
    if (this->size() != maxwindowsize) {
        oldSize = this->size(); //原来的窗口大小
        oldGeometry = this->geometry(); //原来的窗口位置
        ui->maximize->setIcon(QIcon(maxminpicscaled));
        ui->maximize->setIconSize(QSize(20, 20));
        this->setGeometry(0, 0, maxwindowsize.width(), maxwindowsize.height());
    } else {
        this->setGeometry(oldGeometry);
        ui->maximize->setIcon(QIcon(":/tool/maximize.png"));
        ui->maximize->setIconSize(QSize(20, 20));
    }
}

//void Chat::on_send_2_clicked()
//{
//    QDateTime dateTime(QDateTime::currentDateTime());
//    QString qStr = dateTime.toString("yyy-MM-dd hh:mm::ss ddd");
//    QByteArray send_pic = ;//图片解析
//    clientSocket -> sendPicTo(from_id, to_id, qStr, send_pic);
//}

void Chat::on_toolButton_clicked()
{
    //唤起表情弹出框
    QPoint toolbutton = ui->toolButton->mapToGlobal(ui->toolButton->pos());
    qDebug() << toolbutton;
    emo->setGeometry(toolbutton.x() - ui->toolButton->width(), toolbutton.y() - emo->height() - ui->toolButton->height() + 30, emo->width(), emo->height());
    emo->show();
}

void Chat::add_gif(QString gifpath)
{
    qDebug() << gifpath;
    ui->MyMsg->append(QString("%1").arg(gifpath));
}
