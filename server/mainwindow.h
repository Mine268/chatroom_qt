#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "servermanager.h"

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
    void on_closeSrv_clicked();
    void on_startSrv_clicked();

private:
    Ui::MainWindow *ui;
    ServerManager srm;

    // 判断QString是否为字符串
    bool isDigitString(const QString&);
    // 时钟刷新
    virtual void timerEvent(QTimerEvent *e) Q_DECL_OVERRIDE;
};
#endif // MAINWINDOW_H
