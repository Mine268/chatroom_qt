#include "emotionlabel.h"

EmotionLabel::EmotionLabel(QString filepath, QSize emotionsize)
    : QLabel(NULL)
{
    QMovie* emotion = new QMovie(this);
    emotion->setFileName(filepath);
    this->setMovie(emotion);
    emotion->start();
    this->setContentsMargins(3, 3, 3, 3); //设置边距
    emotion->setScaledSize(emotionsize);
    emotion->start();
    emotion->stop();
    setStyleSheet("QLabel:hover{border:1px solid rgb(111,167,207);\
                    background:rgba(255,255,255,200);}");
    this->setAlignment(Qt::AlignCenter);
}

void EmotionLabel::enterEvent(QEvent* event)
{
    QMovie* emotion = this->movie();
    emotion->start();
    setContentsMargins(4, 2, 2, 4);
    QLabel::enterEvent(event);
}

void EmotionLabel::leaveEvent(QEvent* event)
{
    QMovie* emotion = this->movie();
    emotion->stop();
    setContentsMargins(3, 3, 3, 3);
    QLabel::enterEvent(event);
}
