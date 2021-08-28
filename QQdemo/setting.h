#ifndef SETTING_H
#define SETTING_H

#include "fatherwidget.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QWidget>
namespace Ui {
class Setting;
}

class Setting : public FatherWidget {
    Q_OBJECT

public:
    explicit Setting(QWidget* parent = nullptr);
    ~Setting();
    void setSocket(QTcpSocket*);

public slots:
    void close_for_mainWidget();

protected:
private slots:
    void on_minimize_clicked();

    void on_maximize_clicked();

    void on_cancel_clicked();

    void on_sure_clicked();

    void on_close_clicked();

private:
    Ui::Setting* ui;
    QTcpSocket* clientSocket;
    QSize oldSize;
    QRect oldGeometry;
};

#endif // SETTING_H
