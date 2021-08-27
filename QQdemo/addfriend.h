#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QEvent>
#include <QList>
#include <QMouseEvent>
#include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>

namespace Ui {
class AddFriend;
}
struct People {
    QString id;
    QString name;
    int state;
};
class AddFriend : public QWidget {
    Q_OBJECT

public:
    explicit AddFriend(QWidget* parent = nullptr);
    ~AddFriend();
    void setSocket(QTcpSocket*);

protected:
    QPoint old_pos;
    bool mouse_is_press; //鼠标被按下
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

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
};

#endif // ADDFRIEND_H
