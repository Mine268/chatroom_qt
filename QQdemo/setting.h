#ifndef SETTING_H
#define SETTING_H

#include <QEvent>
#include <QMouseEvent>
#include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>

namespace Ui {
class Setting;
}

class Setting : public QWidget {
    Q_OBJECT

public:
    explicit Setting(QWidget* parent = nullptr);
    ~Setting();
    void setSocket(QTcpSocket*);

public slots:
    void close_for_mainWidget();

protected:
    QPoint old_pos;
    bool mouse_is_press; //鼠标被按下
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private slots:
    void on_minimize_clicked();

    void on_maximize_clicked();

    void on_cancel_clicked();

    void on_sure_clicked();

    void on_close_clicked();

private:
    Ui::Setting* ui;
    QTcpSocket* clientSocket;
};

#endif // SETTING_H
