#include "friendlist.h"
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
void FriendList::setSocket(QTcpSocket* _clientSocket)
{
    clientSocket = _clientSocket;
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
void FriendList::mouseMoveEvent(QMouseEvent* event)
{
    //未开启鼠标奥追踪的情况下，当鼠标按下时才能触发
    if (mouse_is_press) {
        this->move(event->globalPos() - old_pos);
    }
}

void FriendList::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        mouse_is_press = true;
        old_pos = event->pos();
        return QWidget::mousePressEvent(event);
    }
}

void FriendList::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    mouse_is_press = false;
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
}

void FriendList::on_treeWidget_itemDoubleClicked(QTreeWidgetItem* item, int column)
{
    //双击好友，打开聊天框
    Chat* chat = new Chat();
    chat->show();
    connect(this, &FriendList::closeMainWidget, chat, &Chat::close_for_mainWidget);
}

void FriendList::on_maximize_clicked()
{
    //最大化
    this->showMaximized();
}
