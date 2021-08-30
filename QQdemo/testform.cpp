#include "testform.h"
#include "friendshow.h"
#include "ui_testform.h"
TestForm::TestForm(QWidget* parent)
    : FatherWidget(parent)
    , ui(new Ui::TestForm)
{
    ui->setupUi(this);
    //    this->setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose);
    //New 一个新的按钮
    //    QPushButton* topLevelButton = new QPushButton("Top Level Button");

    FriendShow* test = new FriendShow(this);
    auto topLevelItem = new QTreeWidgetItem(); //创建一个 TreeItem 容器用于后来装载控件
    ui->treeWidget->addTopLevelItem(topLevelItem); //目的是添加一行 Item
    //设置 Item 内控件，0 是第几列
    ui->treeWidget->setItemWidget(topLevelItem, 0, test);

    FriendShow* test1 = new FriendShow(this);
    auto topLevelItem1 = new QTreeWidgetItem(); //创建一个 TreeItem 容器用于后来装载控件
    ui->treeWidget->addTopLevelItem(topLevelItem1); //目的是添加一行 Item
    //设置 Item 内控件，0 是第几列
    ui->treeWidget->setItemWidget(topLevelItem1, 0, test1);
}

TestForm::~TestForm()
{
    delete ui;
}
