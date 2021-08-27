#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H

#include <QWidget>
#include <QDebug>
#include <QToolButton>

class ToolButton : public QToolButton
{
    Q_OBJECT
public:
    explicit ToolButton(const QString &text, int x, int y, int w, int h, QWidget *parent = nullptr);
    ~ToolButton();
    void enterEvent(QEvent *event); //鼠标进入事件
    void leaveEvent(QEvent *event); //鼠标离开事件
signals:

public slots:
};

#endif // TOOLBUTTON_H
