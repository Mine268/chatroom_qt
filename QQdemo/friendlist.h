#ifndef FRIENDLIST_H
#define FRIENDLIST_H

#include "addfriend.h"
#include "chat.h"
#include "clienttcpsocket.h"
#include "fatherwidget.h"
#include "friendshow.h"
#include "setting.h"
#include <QLineEdit>
#include <QPixmap>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QWidget>
#include <chat.h>

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

    void setdata(QString& id, QString& pwd);

    void setSocket(ClientTcpSocket*);

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

    void showlist(QList<struct user> list);

    void on_searchline_editingFinished();

    void on_searchline_returnPressed();

    void removeChat(QString to_id);
    /*
     * 好友发来消息，如果此时打开了对话框，则显示对话框并添加消息
     * 若未打开对话框，则打开对话框
     * 需要加入检测对话框是否打开的标识
     *
     * */
    void showMessage(struct chat_msg chatmsg);
    /*
     * 检查windowsShow是否已经打开了窗口
     *
     * */
    void on_picture_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem* item, int column);

protected:
private:
    Ui::FriendList* ui;
    ClientTcpSocket* clientSocket;
    QBrush m_itemBrush;
    void searchChild(QTreeWidgetItem* cItem, const QString& txt);
    void parentExpand(QTreeWidgetItem* item);

    QSize oldSize;
    QRect oldGeometry;

    QString userName;
    QString userId;
    QString userPwd;
    QPixmap userpic;
    QMap<QString, Chat*> windowsShow;
};

#endif // FRIENDLIST_H
