#include "friendlist.h"
#include "ui_friendlist.h"

#include <QBrush>
#include <QColor>

FriendList::FriendList(QWidget* parent)
    : FatherWidget(parent)
    , ui(new Ui::FriendList)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::FramelessWindowHint);

    //新添加
    m_itemBrush = ui->treeWidget->topLevelItem(0)->background(0);
    //好友搜索栏
    ui->searchline->setPlaceholderText("输入好友id，点击下方搜索按钮");
    connect(this, SIGNAL(sign_re()), this, SLOT(restore())); //清空好友搜索
}

FriendList::~FriendList()
{
    delete ui;
}
void FriendList::setSocket(ClientTcpSocket* _clientSocket)
{
    clientSocket = _clientSocket;
    //显示好友列表
    connect(clientSocket, &ClientTcpSocket::recvFriendList, this, &FriendList::showlist);
}

void FriendList::on_add_clicked()
{
    //添加好友窗口显示
    AddFriend* addfriend = new AddFriend();
    addfriend->show();
    connect(this, &FriendList::closeMainWidget, addfriend, &AddFriend::close_for_mainWidget);
}

void FriendList::on_setting_clicked()
{
    //设置界面显示
    Setting* setting = new Setting();
    setting->show();
    connect(this, &FriendList::closeMainWidget, setting, &Setting::close_for_mainWidget);
}

void FriendList::on_close_clicked()
{
    //关闭主界面,关闭整个主线程
    emit closeMainWidget();
    this->close();
}

void FriendList::on_minimize_clicked()
{
    //最小化窗口
    this->showMinimized();
}

void FriendList::on_search_clicked()
{
    //搜索好友
    //ToDo :在好友列表中查找是否有此好友并高亮显示
    //完成
    QString txt = ui->searchline->text();
    qDebug() << txt;
    bool isEmptyTxt = txt.isEmpty();

    //复原
    if (isEmptyTxt) {
        emit sign_re();
        return;
    }

    bool isEmptyTree = ui->treeWidget->topLevelItemCount();
    if (!isEmptyTree) {
        qDebug() << "tree empty";
        return;
    }

    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it) {
        for (int i = 0; i < (*it)->columnCount(); i++) {
            if ((*it)->text(i).contains(txt)) {
                qDebug() << "find!";
                (*it)->setBackground(i, QBrush(QColor(0, 0, 255, 60)));
                (*it)->setHidden(false);
                QTreeWidgetItem* item = *it;
                //显示父节点
                while (item->parent()) {
                    item->parent()->setHidden(false);
                    item->parent()->setExpanded(true);
                    item = item->parent();
                }
            } else {
                //不满足满足条件的子结点隐藏
                if ((*it)->parent()) {
                    (*it)->setHidden(true);
                }
            }
        }
        ++it;
    }
}

void FriendList::on_treeWidget_itemDoubleClicked(QTreeWidgetItem* item, int column)
{
    Q_UNUSED(column);
    //有修改
    if (item->parent()) {
        //列表颜色复原
        item->parent()->setSelected(true);
        qDebug() << item->isSelected();
        qDebug() << item->text(0);
        emit sign_re();

        //获取好友信息
        //随便写写
        struct user u = item->data(0, Qt::UserRole + 1).value<struct user>();
        QString name = u.name;
        QString to_id = u.id;

        //双击好友，打开聊天框
        Chat* chat = new Chat();
        chat->setInfo(userId, to_id, name);
        chat->show();
        connect(this, &FriendList::closeMainWidget, chat, &Chat::close_for_mainWidget);
    }
}

void FriendList::on_maximize_clicked()
{
    //最大化
    this->showMaximized();
}

//新添加
//清空搜索
void FriendList::restore()
{
    qDebug() << "txt empty";
    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it) {
        (*it)->setBackground(0, m_itemBrush);
        if (!(*it)->isSelected()) {
            (*it)->setExpanded(false);
        }

        (*it)->setSelected(false);
        it++;
    }
    return;
}

//获取、显示个人信息
void FriendList::getinfo(QString id, QString pwd)
{
    userId = id;
    userPwd = pwd;
    userName = "unknow";
    ui->name->setText(userName);
    ui->id->setText(userId);
}

//显示好友列表
void FriendList::showlist(QList<struct user> list)
{
    QTreeWidgetItem* root = new QTreeWidgetItem;
    ui->treeWidget->addTopLevelItem(root);
    root->setText(0, "new");
    for (int i = 0; i < list.size(); ++i) {
        QTreeWidgetItem* it = new QTreeWidgetItem;
        struct user u = list[i];
        it->setData(1, Qt::UserRole + 1, QVariant::fromValue(u));
        it->setText(0, u.name);
        root->addChild(it);
    }
    //test code
    QTreeWidgetItem* it = new QTreeWidgetItem;
    struct user* uu = new struct user;
    uu->id = "123456";
    uu->name = "myname";
    it->setData(1, Qt::UserRole + 1, QVariant::fromValue(uu));
    it->setText(0, uu->name);
    root->addChild(it);
}
