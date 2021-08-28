#ifndef FATHERWIDGET_H
#define FATHERWIDGET_H

#include "windows.h"
#include "windowsx.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QWidget>

class FatherWidget : public QWidget {
    Q_OBJECT
public:
    explicit FatherWidget(QWidget* parent = nullptr);

signals:
private:
    QSize oldSize;
    QRect oldGeometry;
    int boundaryWidth;

protected:
    QPoint old_pos;
    bool mouse_is_press; //鼠标被按下
    void mouseMoveEvent(QMouseEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    bool nativeEvent(const QByteArray& eventType, void* message, long* result) override;
};

#endif // FATHERWIDGET_H
