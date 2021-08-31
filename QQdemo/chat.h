#ifndef CHAT_H
#define CHAT_H

#include "clienttcpsocket.h"
#include "emotionwidget.h"
#include "fatherwidget.h"
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTime>
#include <QTimer>
#include <QWidget>
#include <showmessage.h>
namespace Ui {
class Chat;
}

class Chat : public FatherWidget {
    Q_OBJECT

public:
    explicit Chat(QWidget* parent = nullptr);
    ~Chat();
    void setSocket(ClientTcpSocket*);
    void setInfo(QString my_id, QString your_id, QString friendname, QString myname);

    void chat_msg_display(chat_msg chatmsg);

public slots:
    void close_for_mainWidget();
    void hidelabel();
private slots:

    void on_close_clicked();

    void on_minimize_clicked();

    void on_send_clicked();

    void on_empty_clicked();

    void on_maximize_clicked();

    void on_toolButton_clicked();

    void add_gif(QString gifpath);

signals:
    void closeChat(QString);

protected:
private:
    Ui::Chat* ui;
    ClientTcpSocket* clientSocket;
    QSize oldSize;
    QRect oldGeometry;
    QLabel* label;
    QTimer* timer;
    QString from_id; //本人id
    QString to_id; //对方id
    QString username; //对方名字
    QString username_me; //本人名称
    EmotionWidget* emo;
};

#endif // CHAT_H
