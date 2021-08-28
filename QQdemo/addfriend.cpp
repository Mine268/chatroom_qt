#include "addfriend.h"
#include "ui_addfriend.h"

AddFriend::AddFriend(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::AddFriend)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_DeleteOnClose);
    ui->lineEdit->setPlaceholderText("请输入Name/Id");
}

AddFriend::~AddFriend()
{
    delete ui;
}

void AddFriend::setSocket(QTcpSocket* _clientSocket)
{
    clientSocket = _clientSocket;
    //ToDo
    //connect( , , , receive_friendlist);
}

void AddFriend::mouseMoveEvent(QMouseEvent* event)
{
    //未开启鼠标奥追踪的情况下，当鼠标按下时才能触发
    if (mouse_is_press) {
        this->move(event->globalPos() - old_pos);
    }
}

void AddFriend::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        mouse_is_press = true;
        old_pos = event->pos();
        return QWidget::mousePressEvent(event);
    }
}

void AddFriend::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    mouse_is_press = false;
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
    //最大化窗口
    this->showMaximized();
}

void AddFriend::on_pushButton_clicked()
{
    //查找好友，需要发送消息
    //ToDo :clientsocket.send*
    //没写
    //test code
    QList<People> list;
    receive_friendlist(list);
}

void AddFriend::on_lineEdit_returnPressed()
{
    //回车查找
    on_pushButton_clicked();
}

void AddFriend::receive_friendlist(QList<People>)
{
    //根据返回的列表构建QTableWidget
    //ToDo
    //未完成
    //处理QList
    //
    //设置表头
    QStandardItemModel *model = new QStandardItemModel();
    model->setColumnCount(3);
    model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("Id"));
    model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("name"));
    model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("add"));
    //设置表格
    ui->tableView->setModel(model);
    //设置列宽不可变
//    ui->tableView->horizontalHeader()->setResizeMode(1,QHeaderView::Fixed);
    ui->tableView->setColumnWidth(0,200);
    ui->tableView->setColumnWidth(1,200);
    ui->tableView->setColumnWidth(2,50);
    for(int i = 0; i < 3; i++)
    {
        QString txt;
        if(i == 0)
        {
             txt = "a";
        }
        else if(i == 1)
        {
            txt = "b";
        }
        else
        {
            txt = "c";
        }

        model->setItem(i,0,new QStandardItem(txt));
        ui->tableView->setRowHeight(i, 40);
        //设置字符颜色、位置
        model->item(i,0)->setForeground(QBrush(QColor(255, 0, 0)));
        model->item(i,0)->setTextAlignment(Qt::AlignCenter);
        model->setItem(i,1,new QStandardItem(QString::fromLocal8Bit("i*20")));
        model->item(i,1)->setTextAlignment(Qt::AlignCenter);
        //添加按钮
        QPushButton *add_button = new QPushButton();
        add_button->setStyleSheet("QPushButton{"
                                  "border-radius: 10px;"
                                  "image: url(:/friendlist/add.png);"
                                  "width:40px;height:40px;"
                                  "padding:5px 0px}");
        add_button->setProperty("row", i);
        add_button->setProperty("column", 2);
        //为按钮设置id属性,可以传输给socket
        add_button->setProperty("id", model->item(i, 0)->text());
        qDebug() << add_button->property("id");
        ui->tableView->setIndexWidget(model->index(model->rowCount() - 1, 2), add_button);
//        connect(add_button, SIGNAL(clicked()), ,)
    }
}

void AddFriend::close_for_mainWidget()
{
    //主窗口的关闭将所有页面关闭
    this->close();
}
