#ifndef SIGNINDIALOG_H
#define SIGNINDIALOG_H

#include <QDialog>
#include <QEvent>
#include <QMouseEvent>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtDebug>
#include <qgraphicseffect.h>

/*
 * 注册窗口的实现
 *
 * */

namespace Ui {
class signinDialog;
}

class signinDialog : public QDialog {
    Q_OBJECT

public:
    explicit signinDialog(QWidget* parent = nullptr);
    ~signinDialog();

    void setSocket(QTcpSocket*); //设置socket
    void init_ui(); //初始化ui界面

signals:
    void okToRegister(QString); //当注册成功时会发送此信号，QString包含ID
    void closeDialog();

private:
    Ui::signinDialog* ui;
    QTcpSocket* ClientSocket;

protected:
    QPoint old_pos;
    bool mouse_is_press; //鼠标被按下
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private slots:
    void on_cancel_clicked();
    void on_sure_clicked();
    void receiveRgMsg(QString);
};

#endif // SIGNINDIALOG_H
