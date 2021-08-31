#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include "addfriendshow.h"
#include "clienttcpsocket.h"
#include "fatherwidget.h"
#include <QList>
#include <QListWidget>
#include <QListWidgetItem>
#include <QStandardItemModel>
#include <QWidget>
namespace Ui {
class AddFriend;
}

class AddFriend : public FatherWidget {
    Q_OBJECT

public:
    explicit AddFriend(QWidget* parent = nullptr);
    ~AddFriend();
    void setSocket(ClientTcpSocket*);
    void setinfo(QString userName, QString userId);

signals:

private slots:
    void on_close_clicked();

    void on_minimize_clicked();

    void on_maximize_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void receive_friendlist(struct user);

    void addfriend(QString);

public slots:
    void close_for_mainWidget();

private:
    Ui::AddFriend* ui;
    ClientTcpSocket* clientSocket;
    QStandardItemModel* model;
    QSize oldSize;
    QRect oldGeometry;

    QString userName;
    QString userId;
};

#endif // ADDFRIEND_H
