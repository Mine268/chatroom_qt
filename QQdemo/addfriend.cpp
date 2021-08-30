#include "addfriend.h"
#include "ui_addfriend.h"

AddFriend::AddFriend(QWidget* parent)
    : FatherWidget(parent)
    , ui(new Ui::AddFriend)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->lineEdit->setPlaceholderText("请输入Id");
}

AddFriend::~AddFriend()
{
    delete ui;
}

void AddFriend::setSocket(ClientTcpSocket* _clientSocket)
{
    clientSocket = _clientSocket;
    //    connect(ui->pushButton; ClientTcpSocket::searchUser; ui->tableView; AddFriend::receive_friendlist);
    connect(ui->tableView, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(send_add_friend(int, int)));
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
    QPixmap maxminpic(":/tool/maxmin.png");
    QPixmap maxminpicscaled = maxminpic.scaled(20, 20);
    if (this->size() != maxwindowsize) {
        oldSize = this->size(); //原来的窗口大小
        oldGeometry = this->geometry(); //原来的窗口位置
        ui->maximize->setIcon(QIcon(maxminpicscaled));
        ui->maximize->setIconSize(QSize(20, 20));
        this->setGeometry(0, 0, maxwindowsize.width(), maxwindowsize.height());
    } else {
        this->setGeometry(oldGeometry);
        ui->maximize->setIcon(QIcon(":/tool/maximize.png"));
        ui->maximize->setIconSize(QSize(20, 20));
    }
}

void AddFriend::on_pushButton_clicked()
{
    //查找好友，需要发送消息
    //ToDo :clientsocket.send*
    //
    qDebug() << "搜索好友";
    QString id = ui->lineEdit->text();
    clientSocket->searchUser(userId, id);
}

void AddFriend::on_lineEdit_returnPressed()
{
    //回车查找
    on_pushButton_clicked();
}

void AddFriend::receive_friendlist(struct user userinfo)
{
    //根据返回的列表构建QTableWidget
    //ToDo
    //未完成
    //处理QList
    //
    //设置表头
    qDebug() << userinfo.id << userinfo.name;

    QList<struct user> list;
    list.append(userinfo);
    model = new QStandardItemModel();
    model->setColumnCount(3);
    model->setHeaderData(0, Qt::Horizontal, "Id");
    model->setHeaderData(1, Qt::Horizontal, "name");
    model->setHeaderData(2, Qt::Horizontal, "add");
    //设置表格
    ui->tableView->setModel(model);
    //设置列宽不可变
    //    ui->tableView->horizontalHeader()->setResizeMode(1,QHeaderView::Fixed);
    ui->tableView->setColumnWidth(0, 200);
    ui->tableView->setColumnWidth(1, 200);
    ui->tableView->setColumnWidth(2, 50);

    for (int i = 0; i < list.size(); i++) {
        ui->tableView->setRowHeight(i, 40);
        model->setItem(i, 0, new QStandardItem(list[i].name));
        model->setItem(i, 1, new QStandardItem(list[i].id));
        //设置字符颜色、位置
        //        model->item(i, 0)->setForeground(QBrush(QColor(255, 0, 0)));
        model->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        model->item(i, 1)->setTextAlignment(Qt::AlignCenter);
        //按钮
        model->setItem(i, 2, new QStandardItem());
        model->item(i, 2)->setIcon(QIcon(":/friendlist/add.png"));

        //        //添加按钮
        //        QPushButton* add_button = new QPushButton();
        //        add_button->setStyleSheet("QPushButton{"
        //                                  "border-radius: 10px;"
        //                                  "image: url(:/friendlist/add.png);"
        //                                  "width:40px;height:40px;"
        //                                  "padding:5px 0px}");
        //        add_button->setProperty("row", i);
        //        add_button->setProperty("column", 2);
        //        //为按钮设置id属性,可以传输给socket
        //        add_button->setProperty("id", model->item(i, 0)->text());
        //        qDebug() << add_button->property("id");
        //        ui->tableView->setIndexWidget(model->index(model->rowCount() - 1, 2), add_button);
    }

    //test
    for (int i = 0; i < 2; i++) {
        QString txt;
        if (i == 0) {
            txt = "a";
        } else if (i == 1) {
            txt = "b";
        } else {
            txt = "c";
        }

        model->setItem(i, 0, new QStandardItem(txt));
        ui->tableView->setRowHeight(i, 40);
        //设置字符颜色、位置
        model->item(i, 0)->setForeground(QBrush(QColor(255, 0, 0)));
        model->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i, 1, new QStandardItem(i));
        model->item(i, 1)->setTextAlignment(Qt::AlignCenter);
        //添加按钮
        qDebug() << "~~~~~~~";
        model->item(i, 2)->setIcon(QIcon(":/friendlist/add.png"));
    }
}

void AddFriend::close_for_mainWidget()
{
    //主窗口的关闭将所有页面关闭
    this->close();
}

void AddFriend::send_add_friend(int row, int col)
{
    // col == 2 是点击按钮
    if (col == 2) {
        //获取id
        QString id = model->item(row, col)->text();
        //调用socket
        emit add_friend(id);
    }
}
