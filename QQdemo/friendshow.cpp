#include "friendshow.h"
#include "ui_friendshow.h"

FriendShow::FriendShow(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::FriendShow)
{
    ui->setupUi(this);
}

FriendShow::~FriendShow()
{
    delete ui;
}

void FriendShow::setData(QString name, QString picturePath, bool state)
{
    ui->lineEdit->setText(name);
    ui->lineEdit->setEnabled(false);
    QPalette pal = ui->lineEdit->palette();
    if (state)
        pal.setColor(QPalette::Text, QColor(255, 255, 22));
    ui->lineEdit->setPalette(pal);
    ui->label->setPixmap(QPixmap(picturePath).scaled(30, 30));
    ui->lineEdit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
}
