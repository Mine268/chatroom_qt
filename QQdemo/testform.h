#ifndef TESTFORM_H
#define TESTFORM_H

#include "fatherwidget.h"
#include <QPushButton>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QWidget>
namespace Ui {
class TestForm;
}

class TestForm : public FatherWidget {
    Q_OBJECT

public:
    explicit TestForm(QWidget* parent = nullptr);
    ~TestForm();

private:
    Ui::TestForm* ui;
};

#endif // TESTFORM_H
