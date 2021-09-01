#include "addfriend.h"
#include "ui_addfriend.h"

AddFriend::AddFriend(QWidget* parent)
    : FatherWidget(parent)
    , ui(new Ui::AddFriend)
{
    ui->setupUi(this);
    ui->lineEdit->setPlaceholderText("请输入Id");

    QGraphicsDropShadowEffect* effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(0, 0); //设置阴影距离
    effect->setColor(QColor(38, 78, 119, 127)); //设置阴影颜色
    effect->setBlurRadius(20); //设置阴影圆角
    ui->frame->setGraphicsEffect(effect);
}

AddFriend::~AddFriend()
{
    delete ui;
}

void AddFriend::setSocket(ClientTcpSocket* _clientSocket)
{
    clientSocket = _clientSocket;
    connect(clientSocket, &ClientTcpSocket::recvUserInfo, this, &AddFriend::receive_friendlist);
}

void AddFriend::setinfo(QString _userName, QString _userId)
{
    userId = _userId;
    userName = _userName;
}

void AddFriend::on_close_clicked()
{
    //关闭窗口
    this->close();
}

void AddFriend::on_minimize_clicked()
{
    //最小化窗口
    this->showMinimized();
}

void AddFriend::on_maximize_clicked()
{
    //最大化窗口，然后改变图标
    QSize maxwindowsize = QApplication::desktop()->size();
    qDebug() << "~~~~!!!" << maxwindowsize;

    QPixmap maxminpic(":/tool/maxmin.png");
    QPixmap maxminpicscaled = maxminpic.scaled(20, 20);
    if (this->size() != maxwindowsize) {
        oldSize = this->size(); //原来的窗口大小
        oldGeometry = this->geometry(); //原来的窗口位置
        ui->maximize->setIcon(QIcon(maxminpicscaled));
        ui->maximize->setIconSize(QSize(25, 25));
        this->setGeometry(0, 0, maxwindowsize.width(), maxwindowsize.height());
    } else {
        this->setGeometry(oldGeometry);
        ui->maximize->setIcon(QIcon(":/tool/maximize.png"));
        ui->maximize->setIconSize(QSize(25, 25));
    }
}

void AddFriend::on_pushButton_clicked()
{
    //查找好友，需要发送消息
    //ToDo :clientsocket.send*
    //
    QString id = ui->lineEdit->text();
    if (!id.isEmpty())
        clientSocket->searchUser(userId, id);
}

void AddFriend::on_lineEdit_returnPressed()
{
    //回车查找
    on_pushButton_clicked();
}

void AddFriend::receive_friendlist(struct user userinfo)
{
    //根据返回的列表构建QListWidget
    //ToDo
    //处理QList
    ui->listWidget->clear();

    qDebug() << userinfo.name << "~~~~~~";
    if (userinfo.name.isEmpty())
        return;
    addFriendshow* searchfriend = new addFriendshow();
    searchfriend->setData(userinfo.name, userinfo.id, data(userinfo.name));
    QListWidgetItem* item = new QListWidgetItem;
    item->setSizeHint(QSize(200, 50));
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item, searchfriend);
    connect(searchfriend, &addFriendshow::addfriend, this, &AddFriend::addfriend);
}

void AddFriend::addfriend(QString id)
{
    //添加好友
    qDebug() << userId << id << "!!!!";
    clientSocket->sendFriendAdd(userId, id);
    //    clientSocket->sendFriendList(userId);
}

void AddFriend::close_for_mainWidget()
{
    //主窗口的关闭将所有页面关闭

    this->close();
}
