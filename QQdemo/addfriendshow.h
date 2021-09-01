#ifndef ADDFRIENDSHOW_H
#define ADDFRIENDSHOW_H

#include <QWidget>

/*
 *
 * 搜索好友并添加显示实现
 *
 * */
namespace Ui {
class addFriendshow;
}

class addFriendshow : public QWidget {
    Q_OBJECT

public:
    explicit addFriendshow(QWidget* parent = nullptr);
    ~addFriendshow();
    void setData(QString, QString, QPixmap picture, bool = true);
private slots:
    void on_addfriendbutton_clicked();
signals:
    void addfriend(QString);

private:
    Ui::addFriendshow* ui;
    QString id;
};

#endif // ADDFRIENDSHOW_H
