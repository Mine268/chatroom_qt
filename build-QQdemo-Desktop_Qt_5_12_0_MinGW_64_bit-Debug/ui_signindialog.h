/********************************************************************************
** Form generated from reading UI file 'signindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNINDIALOG_H
#define UI_SIGNINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_signinDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_5;
    QSpacerItem *horizontalSpacer;
    QLineEdit *passward;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *passward_r;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *username;
    QSpacerItem *verticalSpacer_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *sure;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QDialog *signinDialog)
    {
        if (signinDialog->objectName().isEmpty())
            signinDialog->setObjectName(QString::fromUtf8("signinDialog"));
        signinDialog->resize(427, 335);
        horizontalLayout = new QHBoxLayout(signinDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame = new QFrame(signinDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setMaximumSize(QSize(417, 335));
        frame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background-color:rgb(231,234,237);\n"
"	border:none;\n"
"	border-radius:15px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        horizontalSpacer = new QSpacerItem(101, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 0, 1, 1);

        passward = new QLineEdit(frame);
        passward->setObjectName(QString::fromUtf8("passward"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(passward->sizePolicy().hasHeightForWidth());
        passward->setSizePolicy(sizePolicy);
        passward->setMinimumSize(QSize(185, 0));
        passward->setMaximumSize(QSize(185, 16777215));
        passward->setEchoMode(QLineEdit::Password);
        passward->setReadOnly(false);

        gridLayout_5->addWidget(passward, 3, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 2, 1, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setMinimumSize(QSize(81, 22));
        label_3->setMaximumSize(QSize(81, 22));
        label_3->setStyleSheet(QString::fromUtf8(""));

        gridLayout_5->addWidget(label_3, 5, 2, 1, 1);

        verticalSpacer = new QSpacerItem(191, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_5->addItem(verticalSpacer, 0, 1, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(81, 22));
        label_2->setMaximumSize(QSize(81, 22));

        gridLayout_5->addWidget(label_2, 3, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_3, 4, 1, 1, 1);

        passward_r = new QLineEdit(frame);
        passward_r->setObjectName(QString::fromUtf8("passward_r"));
        sizePolicy.setHeightForWidth(passward_r->sizePolicy().hasHeightForWidth());
        passward_r->setSizePolicy(sizePolicy);
        passward_r->setMinimumSize(QSize(185, 0));
        passward_r->setMaximumSize(QSize(185, 16777215));
        passward_r->setEchoMode(QLineEdit::Password);
        passward_r->setDragEnabled(false);
        passward_r->setReadOnly(false);

        gridLayout_5->addWidget(passward_r, 5, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(101, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        username = new QLineEdit(frame);
        username->setObjectName(QString::fromUtf8("username"));
        sizePolicy.setHeightForWidth(username->sizePolicy().hasHeightForWidth());
        username->setSizePolicy(sizePolicy);
        username->setMinimumSize(QSize(185, 0));
        username->setMaximumSize(QSize(185, 16777215));

        gridLayout_5->addWidget(username, 1, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_4, 6, 1, 1, 1);

        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(91, 22));
        label->setMaximumSize(QSize(91, 22));

        gridLayout_5->addWidget(label, 1, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setMaximumSize(QSize(20, 20));
        checkBox->setStyleSheet(QString::fromUtf8("QCheckBox::indicator::unchecked{\n"
"    image: url(:/eye/openeye.png);width:20px;height:20px;\n"
"}\n"
"QCheckBox::indicator::checked{\n"
"    image: url(:/eye/closeeye.png);width:20px;height:20px;\n"
"}"));

        horizontalLayout_2->addWidget(checkBox);


        gridLayout_5->addLayout(horizontalLayout_2, 3, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_5);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        sure = new QPushButton(frame);
        sure->setObjectName(QString::fromUtf8("sure"));
        sure->setAutoDefault(true);

        horizontalLayout_3->addWidget(sure);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_8);

        cancel = new QPushButton(frame);
        cancel->setObjectName(QString::fromUtf8("cancel"));

        horizontalLayout_3->addWidget(cancel);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);


        horizontalLayout->addWidget(frame);

        QWidget::setTabOrder(sure, cancel);

        retranslateUi(signinDialog);

        QMetaObject::connectSlotsByName(signinDialog);
    } // setupUi

    void retranslateUi(QDialog *signinDialog)
    {
        signinDialog->setWindowTitle(QApplication::translate("signinDialog", "Dialog", nullptr));
        label_3->setText(QApplication::translate("signinDialog", "\344\270\244\346\254\241\345\257\206\347\240\201\344\270\215\345\220\214", nullptr));
        label_2->setText(QApplication::translate("signinDialog", "\345\257\206\347\240\201\344\270\215\350\247\204\350\214\203", nullptr));
        label->setText(QApplication::translate("signinDialog", "\347\224\250\346\210\267\345\220\215\344\270\215\350\203\275\344\270\272\347\251\272", nullptr));
        checkBox->setText(QApplication::translate("signinDialog", "CheckBox", nullptr));
        sure->setText(QApplication::translate("signinDialog", "\347\241\256\350\256\244", nullptr));
        cancel->setText(QApplication::translate("signinDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signinDialog: public Ui_signinDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNINDIALOG_H
