#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include "clienttcpsocket.h"
#include "signindialog.h"
#include <QDialog>
#include <QEvent>
#include <QLineEdit>
#include <QMessageBox>
#include <QMouseEvent>
#include <QSettings>
#include <QTimer>

namespace Ui {
class loginDialog;
}

class loginDialog : public QDialog {
    Q_OBJECT

public:
    explicit loginDialog(QWidget* parent = nullptr);
    ~loginDialog();

    void init_ui();
    void setSocket(ClientTcpSocket*);
    void WriteInit(QString key, QStringList value);
    void ReadInit(QString key, QStringList& value);
    void close_ani();

signals:
    void OkToLogin(QString _userId, QString _userPwd);

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
    void receive_loginOk_message(QString);
    void receive_register_message(QString);
    void receive_loginFail_message(QString);
    void showDialog();
    void on_checkBox_stateChanged(int arg1);
    //private slots里面添加
    void loadpwd(QString);
    void loadpwd(int);
    void close_widget();
    void on_remember_clicked(bool checked);

private:
    Ui::loginDialog* ui;
    QLineEdit* usernumberinput;
    ClientTcpSocket* clientSocket;
    signinDialog* signindialog;
    QString userId;
    QString userPwd;

    QPropertyAnimation* disappear_ani;
    /*
     * 记住密码功能
     *
     * */
    bool need_remember;
    bool is_remember = false;
    QStringList idList;
    QStringList pwdList;
};

#endif // LOGINDIALOG_H
