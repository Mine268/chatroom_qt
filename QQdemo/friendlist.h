#ifndef FRIENDLIST_H
#define FRIENDLIST_H

#include "addfriend.h"
#include "chat.h"
#include "fatherwidget.h"
#include "setting.h"
#include <QLineEdit>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTreeWidget>
#include <QWidget>

/*
 *  FriendList主界面
 *  需要管理添加好友页面，搜索页面，聊天页面等
 *  在主界面关闭时，其天所有页面也将关闭
 * */

namespace Ui {
class FriendList;
}

class FriendList : public FatherWidget {
    Q_OBJECT

public:
    explicit FriendList(QWidget* parent = nullptr);
    ~FriendList();

    void setSocket(QTcpSocket*);

    //设置界面相关控件
    void setUserpicture(QPixmap);
    void setUsernameAndId(QString);

signals:
    void closeMainWidget();
    void sign_re();

private slots:
    void on_add_clicked();

    void on_setting_clicked();

    void on_close_clicked();

    void on_minimize_clicked();

    void on_search_clicked();

    void on_treeWidget_itemDoubleClicked(QTreeWidgetItem* item, int column);

    void on_maximize_clicked();

    void restore();

protected:
private:
    Ui::FriendList* ui;
    QTcpSocket* clientSocket;

    QBrush m_itemBrush;
    void searchChild(QTreeWidgetItem* cItem, const QString& txt);
    void parentExpand(QTreeWidgetItem* item);

    QSize oldSize;
    QRect oldGeometry;
};

#endif // FRIENDLIST_H
