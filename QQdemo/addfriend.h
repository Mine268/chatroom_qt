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
struct People {
    QString id;
    QString name;
    int state;
};
class AddFriend : public FatherWidget {
    Q_OBJECT

public:
    explicit AddFriend(QWidget* parent = nullptr);
    ~AddFriend();
    void setSocket(clienttc*);

protected:
private slots:
    void on_close_clicked();

    void on_minimize_clicked();

    void on_maximize_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

    void receive_friendlist(QList<People>);

public slots:
    void close_for_mainWidget();

private:
    Ui::AddFriend* ui;
    QTcpSocket* clientSocket;
    QSize oldSize;
    QRect oldGeometry;
};

#endif // ADDFRIEND_H
