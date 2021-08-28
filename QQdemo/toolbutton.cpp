#include "toolbutton.h"

#include <QLabel>

ToolButton::ToolButton(const QString &text,
                       int w, int h, QString root,
                       QWidget *parent) : QToolButton(parent)
{
    this->setText(text);
    this->setFixedSize(w, h);
    QString iconname = root + text +".png";
    qDebug() << "mybutton: " << iconname;
    this->setIcon(QIcon(iconname));
}

ToolButton::~ToolButton()
{
}

void ToolButton::enterEvent(QEvent *event)
{
    qDebug() << this->text();
    point = this->point;
    label = new QLabel(this);
    label->setText(this->text());
    label->setScaledContents(true);
    label->move(point.x()+5, point.y());
    label->show();
}

void ToolButton::leaveEvent(QEvent *event)
{
//    qDebug() << "leave";
    label->close();
}

