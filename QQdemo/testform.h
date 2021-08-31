#ifndef TESTFORM_H
#define TESTFORM_H

#include "fatherwidget.h"
#include <QAction>
#include <QBitmap>
#include <QLabel>
#include <QMovie>
#include <QPainter>
#include <QPushButton>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QWidget>

#include "emotionlabel.h"
#include "emotionwidget.h"
namespace Ui {
class TestForm;
}

class TestForm : public QWidget {
    Q_OBJECT

public:
    explicit TestForm(QWidget* parent = nullptr);
    ~TestForm();

    QPixmap pixmapToRound(const QPixmap& srcPixmap, int radius);
    QList<int> data(QString name, int&, int&, int&);

    void addemotionitem(QString filename);

    void initEmotion();

private slots:
    void on_toolButton_pressed();

    void on_toolButton_clicked();

private:
    EmotionWidget* emo;
    Ui::TestForm* ui;
    QList<QString> m_emotionList;
};

#endif // TESTFORM_H
