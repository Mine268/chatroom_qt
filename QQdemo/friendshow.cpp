#include "friendshow.h"
#include "ui_friendshow.h"

FriendShow::FriendShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FriendShow)
{
    ui->setupUi(this);
}

FriendShow::~FriendShow()
{
    delete ui;
}
