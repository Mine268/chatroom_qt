#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include "signindialog.h"
#include <QDialog>
#include <QEvent>
#include <QLineEdit>
#include <QMessageBox>
#include <QMouseEvent>
#include <QTcpServer>
#include <QTcpSocket>

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog {
    Q_OBJECT

public:
    explicit loginDialog(QWidget* parent = nullptr);
    ~loginDialog();

    void init_ui();
    void setSocket(QTcpSocket*);

signals:
    void OkToLogin();

protected:
    QPoint old_pos;
    bool mouse_is_press; //鼠标被按下
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private slots:
    void on_login_clicked();
    void on_regestor_clicked();
    void on_cancel_clicked();

    void receive_login_message(QString);
    void receive_register_message(QString);
    void showDialog();

    void on_checkBox_stateChanged(int arg1);

private:
    Ui::loginDialog* ui;
    QLineEdit* usernumberinput;
    QTcpSocket* clientSocket;
    signinDialog* signindialog;
};

#endif // LOGINDIALOG_H
