#include "testform.h"
#include "friendshow.h"
#include "ui_testform.h"

#include <QCryptographicHash>
#include <QWidget>
#include <QtDebug>

TestForm::TestForm(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::TestForm)
{
    ui->setupUi(this);
    emo = new EmotionWidget(this);
    emo->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
}

TestForm::~TestForm()
{
    delete ui;
}
QPixmap TestForm::pixmapToRound(const QPixmap& srcPixmap, int radius)
{
    if (srcPixmap.isNull()) {
        return QPixmap();
    }
    QSize size(2 * radius, 2 * radius);
    QBitmap mask(size);
    QPainter painter(&mask);
    //painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.fillRect(0, 0, size.width(), size.height(), Qt::white);
    painter.setBrush(QColor(0, 0, 0));
    painter.drawRoundedRect(0, 0, size.width(), size.height(), 999, 999);
    QPixmap image = srcPixmap.scaled(size);
    image.setMask(mask);
    return image;
}

void TestForm::on_toolButton_pressed()
{
}

void TestForm::on_toolButton_clicked()
{

    QPoint toolbutton = ui->toolButton->mapToGlobal(ui->toolButton->pos());

    qDebug() << toolbutton;
    emo->setGeometry(toolbutton.x() - ui->toolButton->width(), toolbutton.y() - emo->height() - ui->toolButton->height() + 30, emo->width(), emo->height());
    //    emo->setGeometry(toolbutton);

    emo->show();
    qDebug() << emo->geometry();
}
