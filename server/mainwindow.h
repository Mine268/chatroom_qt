#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tcpserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_start_server_clicked();

    // 分别对应TcpServer中的signals
    void getLogin(QTcpSocket*, const QString&, const QString&);
    void getRegister(QTcpSocket*, const QString&, const QString&);
    void getMessage(const QString&, const QString&, const QString&, const QString&);
    void getFriendAddQuest(const QString&, const QString&);
    void getFriendDelQuest(const QString&, const QString&);

private:
    Ui::MainWindow *ui;
    TcpServer *server;
};
#endif // MAINWINDOW_H
