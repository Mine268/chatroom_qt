#ifndef CHAT_H
#define CHAT_H

#include "fatherwidget.h"
#include "clienttcpsocket.h"
#include <QWidget>
#include <QTime>

namespace Ui {
class Chat;
}

class Chat : public FatherWidget {
    Q_OBJECT

public:
    explicit Chat(QWidget* parent = nullptr);
    ~Chat();
    void setSocket(ClientTcpSocket*);
    void setInfo(QString my_id, QString your_id, QString name);

public slots:
    void close_for_mainWidget();
private slots:

    void on_close_clicked();

    void on_minimize_clicked();

    void on_send_clicked();

    void on_empty_clicked();

    void on_maximize_clicked();

//    void on_send_2_clicked();

    void on_send_2_clicked();

protected:
private:
    Ui::Chat* ui;
    ClientTcpSocket* clientSocket;
    QSize oldSize;
    QRect oldGeometry;
    QString from_id;
    QString to_id;
    QString username;

};

#endif // CHAT_H
