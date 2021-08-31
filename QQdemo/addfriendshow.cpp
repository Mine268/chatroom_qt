#include "addfriendshow.h"
#include "ui_addfriendshow.h"

addFriendshow::addFriendshow(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::addFriendshow)
{
    ui->setupUi(this);
}

addFriendshow::~addFriendshow()
{
    delete ui;
}

void addFriendshow::setData(QString name, QString _id, QPixmap picture, bool state)
{
    ui->username->setText(name);
    ui->username->setEnabled(false);
    id = _id;
    QPalette pal = ui->username->palette();
    if (state)
        pal.setColor(QPalette::Text, QColor(0, 0, 0));
    ui->username->setPalette(pal);
    ui->userpic->setPixmap(picture.scaled(30, 30));
    ui->username->setStyleSheet("background:transparent;border-width:0;border-style:outset");
}

void addFriendshow::on_addfriendbutton_clicked()
{
    //按添加按钮发送信号并设置不可再按
    emit addfriend(id);
    ui->addfriendbutton->setEnabled(false);
}
