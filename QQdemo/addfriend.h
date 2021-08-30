#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include "clienttcpsocket.h"
#include "fatherwidget.h"
#include <QList>
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
    void add_friend(QString);

protected:
private slots:
    void on_close_clicked();

    void on_minimize_clicked();

    void on_maximize_clicked();

    void send_add_friend(int row, int col);

    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void receive_friendlist(struct user);

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
