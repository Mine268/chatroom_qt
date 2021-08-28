#include "friendlist.h"
#include "ui_friendlist.h"

#include <QBrush>
#include <QColor>

FriendList::FriendList(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::FriendList)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::FramelessWindowHint);

    //新添加
    m_itemBrush =  ui->treeWidget->topLevelItem(0)->background(0);
    //好友搜索栏
    ui->searchline->setPlaceholderText("输入好友id，点击下方搜索按钮");
    connect(this, SIGNAL(sign_re()), this, SLOT(restore()));

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
    //完成
    QString txt = ui->searchline->text();
    qDebug() << txt;
    bool isEmptyTxt = txt.isEmpty();

    //复原
    if (isEmptyTxt)
    {
        emit sign_re();
        return;
    }

    bool isEmptyTree = ui->treeWidget->topLevelItemCount();
    if ( ! isEmptyTree)
    {
        qDebug() << "tree empty";
        return;
    }

    QTreeWidgetItemIterator it(ui->treeWidget);
    while (*it)
    {
        for(int i = 0; i < (*it)->columnCount(); i++)
        {
            if((*it)->text(i).contains(txt))
            {
                qDebug() << "find!";
                (*it)->setBackground(i, QBrush(QColor(0, 0, 255, 60)));
                (*it)->setHidden(false);
                QTreeWidgetItem *item = *it;
                //显示父节点
                while (item->parent())
                {
                    item->parent()->setHidden(false);
                    item->parent()->setExpanded(true);
                    item = item->parent();
                }
            }
            else
            {
                 //不满足满足条件的子结点隐藏
                if((*it)->parent())
                {
                    (*it)->setHidden(true);
                }
            }
        }
        ++it;
    }
}

void FriendList::on_treeWidget_itemDoubleClicked(QTreeWidgetItem* item, int column)
{
    //有修改
    if(item->parent())
    {
        //列表颜色复原
        item->parent()->setSelected(true);
        qDebug() << item->isSelected();
        qDebug() << item->text(0);
        emit sign_re();

        //双击好友，打开聊天框
        Chat* chat = new Chat();
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
void FriendList::restore()
{
    qDebug() << "txt empty";
    QTreeWidgetItemIterator it(ui->treeWidget);
    while(*it) {
        (*it)->setBackground(0, m_itemBrush);
        if(!(*it)->isSelected())
        {
            (*it)->setExpanded(false);
//            (*it)->setHidden(false);
        }

        (*it)->setSelected(false);
        it++;
    }
    return;
}
