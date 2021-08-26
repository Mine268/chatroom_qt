#ifndef SIGNINDIALOG_H
#define SIGNINDIALOG_H

#include <QDialog>
#include <QEvent>
#include <QMouseEvent>
#include <QTcpServer>
#include <QTcpSocket>
#include <QtDebug>
#include <qgraphicseffect.h>
namespace Ui {
class signinDialog;
}

class signinDialog : public QDialog {
    Q_OBJECT

public:
    explicit signinDialog(QWidget* parent = nullptr);
    ~signinDialog();

    void setSocket();

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
};

#endif // SIGNINDIALOG_H
