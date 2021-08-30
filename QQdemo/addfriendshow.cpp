#include "addfriendshow.h"
#include "ui_addfriendshow.h"

addFriendshow::addFriendshow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addFriendshow)
{
    ui->setupUi(this);
}

addFriendshow::~addFriendshow()
{
    delete ui;
}
