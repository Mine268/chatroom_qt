/********************************************************************************
** Form generated from reading UI file 'addfriend.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFRIEND_H
#define UI_ADDFRIEND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFriend
{
public:
    QFrame *frame;
    QLabel *label;
    QFrame *frame_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *tool;
    QPushButton *minimize;
    QPushButton *maximize;
    QPushButton *close;
    QTableView *tableView;

    void setupUi(QWidget *AddFriend)
    {
        if (AddFriend->objectName().isEmpty())
            AddFriend->setObjectName(QString::fromUtf8("AddFriend"));
        AddFriend->resize(650, 550);
        AddFriend->setMaximumSize(QSize(650, 550));
        frame = new QFrame(AddFriend);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 0, 650, 550));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 160, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Microsoft YaHei UI"));
        font.setPointSize(10);
        label->setFont(font);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(0, 40, 650, 50));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(15, 5, 520, 40));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font1.setPointSize(10);
        lineEdit->setFont(font1);
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(555, 5, 80, 40));
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(560, 0, 91, 22));
        tool = new QHBoxLayout(horizontalLayoutWidget);
        tool->setSpacing(5);
        tool->setObjectName(QString::fromUtf8("tool"));
        tool->setContentsMargins(0, 0, 0, 0);
        minimize = new QPushButton(horizontalLayoutWidget);
        minimize->setObjectName(QString::fromUtf8("minimize"));
        minimize->setMinimumSize(QSize(20, 20));
        minimize->setMaximumSize(QSize(20, 20));

        tool->addWidget(minimize);

        maximize = new QPushButton(horizontalLayoutWidget);
        maximize->setObjectName(QString::fromUtf8("maximize"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(maximize->sizePolicy().hasHeightForWidth());
        maximize->setSizePolicy(sizePolicy);
        maximize->setMinimumSize(QSize(20, 20));
        maximize->setMaximumSize(QSize(20, 20));

        tool->addWidget(maximize);

        close = new QPushButton(horizontalLayoutWidget);
        close->setObjectName(QString::fromUtf8("close"));
        close->setMinimumSize(QSize(20, 20));
        close->setMaximumSize(QSize(20, 20));

        tool->addWidget(close);

        tableView = new QTableView(frame);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(15, 100, 620, 430));

        retranslateUi(AddFriend);

        QMetaObject::connectSlotsByName(AddFriend);
    } // setupUi

    void retranslateUi(QWidget *AddFriend)
    {
        AddFriend->setWindowTitle(QApplication::translate("AddFriend", "Form", nullptr));
        label->setText(QApplication::translate("AddFriend", "\346\267\273\345\212\240\345\245\275\345\217\213", nullptr));
        lineEdit->setText(QString());
        pushButton->setText(QApplication::translate("AddFriend", "\346\237\245\346\211\276", nullptr));
        minimize->setText(QApplication::translate("AddFriend", "-", nullptr));
        maximize->setText(QApplication::translate("AddFriend", "\345\217\243", nullptr));
        close->setText(QApplication::translate("AddFriend", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddFriend: public Ui_AddFriend {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFRIEND_H
