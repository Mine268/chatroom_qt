#ifndef SHOWMESSAGE_H
#define SHOWMESSAGE_H

#include <QWidget>

namespace Ui {
class showMessage;
}

class showMessage : public QWidget {
    Q_OBJECT

public:
    explicit showMessage(QWidget* parent = nullptr);
    ~showMessage();

    void setinfo(QString username_me, QString qStr, QString html);
private slots:

private:
    Ui::showMessage* ui;
};

#endif // SHOWMESSAGE_H
