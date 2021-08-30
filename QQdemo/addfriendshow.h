#ifndef ADDFRIENDSHOW_H
#define ADDFRIENDSHOW_H

#include <QWidget>

namespace Ui {
class addFriendshow;
}

class addFriendshow : public QWidget
{
    Q_OBJECT

public:
    explicit addFriendshow(QWidget *parent = nullptr);
    ~addFriendshow();

private:
    Ui::addFriendshow *ui;
};

#endif // ADDFRIENDSHOW_H
