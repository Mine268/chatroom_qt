#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srm.configure(QHostAddress::Any,
                  11451,
                  "QODBC",
                  "Driver={MySQL ODBC 8.0 Unicode Driver};DATABASE=mydatabase;",
                  "127.0.0.1",
                  3306,
                  "root",
                  "rkw20089");
    srm.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}
