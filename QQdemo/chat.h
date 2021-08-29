#ifndef CHAT_H
#define CHAT_H

#include "fatherwidget.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>
#include <QPixmap>

namespace Ui {
class Chat;
}

class Chat : public FatherWidget {
    Q_OBJECT

public:
    explicit Chat(QWidget* parent = nullptr);
    ~Chat();
    void setSocket(QTcpSocket*);
    void setInfo(QString me_id, QString your_id, QString name);

public slots:
    void close_for_mainWidget();
private slots:

    void on_close_clicked();

    void on_minimize_clicked();

    void on_send_clicked();

    void on_empty_clicked();

    void on_maximize_clicked();

protected:
private:
    Ui::Chat* ui;
    QTcpSocket* clientSocket;
    QSize oldSize;
    QRect oldGeometry;
};

#endif // CHAT_H
