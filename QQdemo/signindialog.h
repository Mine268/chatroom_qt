#ifndef SIGNINDIALOG_H
#define SIGNINDIALOG_H

#include "clienttcpsocket.h"
#include <QDialog>
#include <QEvent>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
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

    void setSocket(ClientTcpSocket*); //设置socket
    void init_ui(); //初始化ui界面

signals:
    void okToRegister(QString); //当注册成功时会发送此信号，QString包含ID
    void closeDialog();

private:
    Ui::signinDialog* ui;
    ClientTcpSocket* ClientSocket;
    QString warning_background_1 = "border:2px red;"
                                   "border-radius:10px;"
                                   "padding:5px 2px;"
                                   "font: 6pt ;"
                                   "background-color: qlineargradient"
                                   "(spread:pad, x1:0, y1:0, x2:1, y2:0, "
                                   "stop:0 rgba(255, 0, 0, 60), "
                                   "stop:1 rgba(255, 255, 255, 0));";
    QString warning_background_2 = "border:4px red;"
                                   "border-radius:10px;"
                                   "padding:5px 2px;"
                                   "font: 6pt ;"
                                   "background-color: qlineargradient"
                                   "(spread:pad, x1:0, y1:0, x2:1, y2:0, "
                                   "stop:0 rgba(255, 0, 0, 120), "
                                   "stop:1 rgba(255, 255, 255, 0));";

protected:
    QPoint old_pos;
    bool mouse_is_press; //鼠标被按下
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private slots:
    void on_cancel_clicked();
    void on_sure_clicked();
    void receiveRgOkMsg(QString);
    void receiveReFailMsg(QString);
    void on_username_textEdited(const QString& arg1);
    void on_passward_r_textEdited(const QString& arg1);
    void on_checkBox_stateChanged(int arg1);
};

#endif // SIGNINDIALOG_H
