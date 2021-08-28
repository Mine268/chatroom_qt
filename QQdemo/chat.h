#ifndef CHAT_H
#define CHAT_H

#include <QEvent>
#include <QMouseEvent>
#include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>
namespace Ui {
class Chat;
}

class Chat : public QWidget {
    Q_OBJECT

public:
    explicit Chat(QWidget* parent = nullptr);
    ~Chat();
    void setSocket(QTcpSocket*);

public slots:
    void close_for_mainWidget();
private slots:

    void on_close_clicked();

    void on_minimize_clicked();

    void on_send_clicked();

    void on_empty_clicked();

protected:
    QPoint old_pos;
    bool mouse_is_press; //鼠标被按下
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    Ui::Chat* ui;
    QTcpSocket* clientSocket;
};

#endif // CHAT_H
