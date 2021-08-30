#ifndef FRIENDSHOW_H
#define FRIENDSHOW_H

#include <QPalette>
#include <QWidget>
namespace Ui {
class FriendShow;
}

class FriendShow : public QWidget {
    Q_OBJECT

public:
    explicit FriendShow(QWidget* parent = nullptr);
    ~FriendShow();
    void setData(QString name, QString picturePath, bool state);

private:
    Ui::FriendShow* ui;
};

#endif // FRIENDSHOW_H
