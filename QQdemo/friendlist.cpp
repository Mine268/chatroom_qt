#include "friendlist.h"
#include "addfriend.h"
#include "setting.h"
#include "ui_friendlist.h"

FriendList::FriendList(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::FriendList)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::FramelessWindowHint);
}

FriendList::~FriendList()
{
    delete ui;
}

void FriendList::on_add_clicked()
{
    AddFriend* addfriend = new AddFriend;
    addfriend->show();
}

void FriendList::on_setting_clicked()
{
    Setting* setting = new Setting;
    setting->show();
}
