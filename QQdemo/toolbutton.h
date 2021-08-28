#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H

#include <QWidget>
#include <QDebug>
#include <QToolButton>
#include <QString>
#include <QEvent>
#include <QMouseEvent>
#include <QLabel>
#include <QPoint>

class ToolButton : public QToolButton
{
    Q_OBJECT
public:
    explicit ToolButton(const QString &text, int w, int h, QString root, QWidget *parent = nullptr);
    ~ToolButton();
    void enterEvent(QEvent *event); //鼠标进入事件
    void leaveEvent(QEvent *event); //鼠标离开事件
signals:

public slots:

protected:
    QPoint point;

private:
    QLabel *label;
};

#endif // TOOLBUTTON_H
