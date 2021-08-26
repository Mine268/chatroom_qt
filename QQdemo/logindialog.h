#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

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
    void setSocket();
    void ClientRecvData();

private:
    //一些flag
    bool ok;

protected:
    QPoint old_pos;
    bool mouse_is_press; //鼠标被按下
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private slots:
    void on_login_clicked();

private:
    Ui::loginDialog* ui;
    QLineEdit* usernumberinput;
    QTcpSocket* clientSocket;
};

#endif // LOGINDIALOG_H
