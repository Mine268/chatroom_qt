#include "toolbutton.h"

ToolButton::ToolButton(const QString &text,
                       int x, int y, int w, int h,
                       QWidget *parent) : QToolButton(parent)
{
    this->setText(text);
    this->setGeometry(QRect(x, y, w, h));

}

ToolButton::~ToolButton()
{
}

void ToolButton::enterEvent(QEvent *event)
{
    qDebug() << "enter";
}

void ToolButton::leaveEvent(QEvent *event)
{
    qDebug() << "leave";
}
