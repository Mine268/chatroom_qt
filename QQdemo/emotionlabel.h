#ifndef EMOTIONLABEL_H
#define EMOTIONLABEL_H

#include <QEvent>
#include <QLabel>
#include <QMovie>
class EmotionLabel : public QLabel {
public:
    EmotionLabel(QString, QSize);

protected:
    void enterEvent(QEvent*) override;
    void leaveEvent(QEvent*) override;
};

#endif // EMOTIONLABEL_H
