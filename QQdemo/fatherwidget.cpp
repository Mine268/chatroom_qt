#include "fatherwidget.h"

#include <QCryptographicHash>
#include <QPainter>
#include <QPixmap>

FatherWidget::FatherWidget(QWidget* parent)
    : QWidget(parent)
{
    boundaryWidth = 2;
    setAttribute(Qt::WA_DeleteOnClose);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
}

QPixmap FatherWidget::data(QString name)
{
    QByteArray byteArray(name.toLatin1());
    QCryptographicHash hash(QCryptographicHash::Sha512);
    hash.addData(byteArray); // 添加数据到加密哈希值
    QByteArray result = hash.result(); // 返回最终的哈希值
    QString strMD5 = result.toHex();

    //    qDebug() << (unsigned char)result[0] << result.size();

    QList<int> L;
    int temp;
    temp = (unsigned char)result[0];
    while (temp != 0) {
        L.push_front(temp % 2);
        temp = temp >> 1;
    }
    while (L.size() < 8) {
        L.push_front(0);
    }
    temp = (unsigned char)result[1];
    while (temp != 0) {
        L.push_front(temp % 2);
        temp = temp >> 1;
    }
    while (L.size() < 16) {
        L.push_front(0);
    }
    int r = (unsigned char)result[2];
    int g = (unsigned char)result[3];
    int b = (unsigned char)result[4];

    return picture(L, r, g, b);
}

QPixmap FatherWidget::picture(QList<int>& dot, int r, int g, int b)
{
    //创建一个绘图设备，Qimage：：Fomat_ARGB32背景是透明
    QImage image(5, 5, QImage::Format_RGB32);
    QPainter p;
    p.begin(&image);
    //绘图
    p.drawImage(0, 0, QImage("../image/5.jpg"));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            image.setPixel(QPoint(j, i), qRgb(255, 255, 255));
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            //对50x50的像素点 挨个着色
            if (dot[i * 3 + j] == 1)
                image.setPixel(QPoint(j, i), qRgb(r, g, b));
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 3; j < 5; j++) {
            //对50x50的像素点 挨个着色
            if (dot[i * 3 + 4 - j] == 1)
                image.setPixel(QPoint(j, i), qRgb(r, g, b));
        }
    }
    p.end();
    return QPixmap::fromImage(image);
}
void FatherWidget::mouseMoveEvent(QMouseEvent* event)
{
    //未开启鼠标奥追踪的情况下，当鼠标按下时才能触发
    if (mouse_is_press) {
        this->move(event->pos() + pos() - old_pos);
    }
}

void FatherWidget::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        mouse_is_press = true;
        old_pos = event->pos();
        return QWidget::mousePressEvent(event);
    }
}

void FatherWidget::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    mouse_is_press = false;
}
bool FatherWidget::nativeEvent(const QByteArray& eventType, void* message, long* result)
{
    Q_UNUSED(eventType);
    MSG* msg = (MSG*)message;
    switch (msg->message) {
    case WM_NCHITTEST:
        int xPos = GET_X_LPARAM(msg->lParam) - this->frameGeometry().x();
        int yPos = GET_Y_LPARAM(msg->lParam) - this->frameGeometry().y();
        if (xPos < boundaryWidth && yPos < boundaryWidth) //左上角
            *result = HTTOPLEFT;
        else if (xPos >= width() - boundaryWidth && yPos < boundaryWidth) //右上角
            *result = HTTOPRIGHT;
        else if (xPos < boundaryWidth && yPos >= height() - boundaryWidth) //左下角
            *result = HTBOTTOMLEFT;
        else if (xPos >= width() - boundaryWidth && yPos >= height() - boundaryWidth) //右下角
            *result = HTBOTTOMRIGHT;
        else if (xPos < boundaryWidth) //左边
            *result = HTLEFT;
        else if (xPos >= width() - boundaryWidth) //右边
            *result = HTRIGHT;
        else if (yPos < boundaryWidth) //上边
            *result = HTTOP;
        else if (yPos >= height() - boundaryWidth) //下边
            *result = HTBOTTOM;
        else //其他部分不做处理，返回false，留给其他事件处理器处理
            return false;
        return true;
    }
    return false; //此处返回false，留给其他事件处理器处理
}
