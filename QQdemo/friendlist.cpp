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
    //发送好友列表请求
    connect(clientSocket, &ClientTcpSocket::recvFriendList, this, &FriendList::showlist);
    connect(clientSocket, &ClientTcpSocket::recvChatMsg, this, &FriendList::showMessage);
    clientSocket->sendFriendList(userId); //发送请求好友列表
}

void FriendList::on_add_clicked()
{
    //添加好友窗口显示
    AddFriend* addfriend = new AddFriend();
    addfriend->setSocket(clientSocket);
    addfriend->show();
    connect(this, &FriendList::closeMainWidget, addfriend, &AddFriend::close_for_mainWidget);
}

void FriendList::on_setting_clicked()
{
    //设置界面显示
    Setting* setting = new Setting();
    setting->setSocket(clientSocket);
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
    //在好友列表中查找是否有此好友并高亮显示
    //完成
    QString txt = ui->searchline->text();
    bool isEmptyTxt = txt.isEmpty();
    //复原
    if (isEmptyTxt) {
        emit sign_re();
        return;
    }

    //    bool isEmptyTree = ui->treeWidget->topLevelItemCount();
    //    if (!isEmptyTree) {
    //        qDebug() << "tree empty";
    //        return;
    //    }

    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it) {
        for (int i = 0; i < (*it)->columnCount(); i++) {
            if ((*it)->text(i).contains(txt)) {
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
        //获取好友信息
        struct user u = item->data(0, Qt::UserRole + 1).value<struct user>();
        QString name = u.name;
        QString to_id = u.id;

        //双击好友，打开聊天框
        if (windowsShow.contains(to_id)) {
            windowsShow[to_id]->show();
        } else {
            Chat* chat = new Chat();
            windowsShow[to_id] = chat;
            chat->setInfo(userId, to_id, name);
            chat->setSocket(clientSocket);
            chat->show();
            connect(this, &FriendList::closeMainWidget, chat, &Chat::close_for_mainWidget);
            connect(chat, &Chat::closeChat, this, &FriendList::removeChat);
        }
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
    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it) {
        (*it)->setBackground(0, m_itemBrush);
        if (!(*it)->isSelected()) {
            (*it)->setExpanded(true);
        }
        (*it)->setSelected(false);
        it++;
    }
    ui->treeWidget->expandAll();
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
    root->setText(0, "friend");

    qDebug() << list.size();

    for (int i = 0; i < list.size(); ++i) {
        QTreeWidgetItem* it = new QTreeWidgetItem;
        struct user myfriend = list[i];
        it->setData(0, Qt::UserRole + 1, QVariant::fromValue(myfriend));
        it->setText(0, myfriend.name);
        if (myfriend.online != true)
            it->setForeground(0, QBrush(QColor(0, 0, 0))); //不在线
        root->addChild(it);
    }
}

void FriendList::on_searchline_editingFinished()
{
    //当编辑框中方内容为空时恢复界面
    if (ui->searchline->text().isEmpty())
        emit sign_re();
}

void FriendList::on_searchline_returnPressed()
{
    //回车搜索
    on_search_clicked();
}

void FriendList::removeChat(QString to_id)
{
    windowsShow.remove(to_id);
}

void FriendList::showMessage(struct chat_msg chatmsg)
{
    //查看map是否已经打开窗口
    qDebug() << "~~~~~~~~~~~~~~" << chatmsg.from_id << chatmsg.to_id << chatmsg.time << chatmsg.value;

    if (windowsShow.contains(chatmsg.from_id)) {
        //如果已经打开了窗口
        windowsShow[chatmsg.from_id]->chat_msg_display(chatmsg);
        windowsShow[chatmsg.from_id]->show();
    } else {
        //没有打开窗口
        Chat* chat = new Chat();
        windowsShow[chatmsg.from_id] = chat;
        /*
         * 通过fromID查找列表中的用户
         *
         **/
        QString name;

        int size = ui->treeWidget->topLevelItemCount();
        QTreeWidgetItem* father;
        for (int i = 0; i < size; i++) {
            father = ui->treeWidget->topLevelItem(i);
            int childCount = father->childCount();
            int flag = 0;

            for (int j = 0; j < childCount; ++j) {
                QTreeWidgetItem* child = father->child(j);
                struct user people = child->data(0, Qt::UserRole + 1).value<struct user>();
                if (people.id == chatmsg.from_id) {
                    name = people.name;
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
        qDebug() << userId << chatmsg.from_id << name << "!!!!!";

        chat->setInfo(userId, chatmsg.from_id, name);
        chat->setSocket(clientSocket);
        chat->chat_msg_display(chatmsg);
        chat->show();
        connect(chat, &Chat::closeChat, this, &FriendList::removeChat);
        connect(this, &FriendList::closeMainWidget, chat, &Chat::close_for_mainWidget);
    }
}
