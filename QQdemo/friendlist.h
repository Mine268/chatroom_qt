#ifndef FRIENDLIST_H
#define FRIENDLIST_H

#include <QEvent>
#include <QMouseEvent>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTreeWidget>
#include <QWidget>

#include "addfriend.h"
#include "chat.h"
#include "setting.h"
/*
 *  FriendList主界面
 *  需要管理添加好友页面，搜索页面，聊天页面等
 *  在主界面关闭时，其天所有页面也将关闭
 * */

namespace Ui {
class FriendList;
}

class FriendList : public QWidget {
    Q_OBJECT

public:
    explicit FriendList(QWidget* parent = nullptr);
    ~FriendList();
    void setSocket(QTcpSocket*);

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
    QPoint old_pos;
    bool mouse_is_press; //鼠标被按下
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    Ui::FriendList* ui;
    QTcpSocket* clientSocket;

    QBrush m_itemBrush;
    void searchChild(QTreeWidgetItem *cItem, const QString &txt);
    void parentExpand(QTreeWidgetItem *item);
};

#endif // FRIENDLIST_H