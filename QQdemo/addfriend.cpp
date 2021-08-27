#include "addfriend.h"
#include "ui_addfriend.h"

AddFriend::AddFriend(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddFriend)
{
    ui->setupUi(this);
}

AddFriend::~AddFriend()
{
    delete ui;
}
