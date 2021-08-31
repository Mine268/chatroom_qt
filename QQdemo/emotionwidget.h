#ifndef EMOTIONWIDGET_H
#define EMOTIONWIDGET_H

#include "emotionlabel.h"
#include <QFile>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QWidget>
namespace Ui {
class EmotionWidget;
}

class EmotionWidget : public QWidget {
    Q_OBJECT

public:
    explicit EmotionWidget(QWidget* parent = nullptr);
    ~EmotionWidget();
    void setTableInfo();

    void addemotionitem(QString filename);
    void initEmotion();
signals:
    void sendgifpath(QString);
private slots:
    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::EmotionWidget* ui;
    const QSize emotion_size = QSize(40, 40); //emotion大小
    const int emotion_num = 205;
    int row, column; //行列数目
    QList<QString> m_emotionList;
};

#endif // EMOTIONWIDGET_H
