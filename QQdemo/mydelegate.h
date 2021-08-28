#ifndef MYDELEGATE_H
#define MYDELEGATE_H

#include <QStyledItemDelegate>
#include <QObject>

class Mydelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit Mydelegate(QObject *parent = nullptr);
};

#endif // MYDELEGATE_H
