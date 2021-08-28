/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
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

class Ui_loginDialog
{
public:
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *picture;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QGridLayout *gridLayout;
    QLineEdit *userpassward;
    QSpacerItem *horizontalSpacer_7;
    QComboBox *usernumber;
    QSpacerItem *horizontalSpacer_8;
    QCheckBox *checkBox;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QPushButton *login;
    QPushButton *regestor;
    QPushButton *cancel;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QDialog *loginDialog)
    {
        if (loginDialog->objectName().isEmpty())
            loginDialog->setObjectName(QString::fromUtf8("loginDialog"));
        loginDialog->resize(435, 336);
        loginDialog->setWindowOpacity(1.000000000000000);
        loginDialog->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:2px groove rgb(231,234,237);\n"
"	border-radius:10px;\n"
"	padding:2px 4px;\n"
"	border-style: outset;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color:rgb(229, 241, 251); color: black;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color:rgb(204, 228, 247);\n"
"	border-style: inset;\n"
"}\n"
"QLabel{\n"
"	border-radius: 65px;\n"
"	border:1px solid black;\n"
"	background: green; \n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(loginDialog);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        frame = new QFrame(loginDialog);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("QFrame\n"
"{\n"
"	background-color:rgb(231,234,237);\n"
" \n"
"	border:none;\n"
"	border-radius:15px;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        picture = new QLabel(frame);
        picture->setObjectName(QString::fromUtf8("picture"));
        picture->setMinimumSize(QSize(130, 130));
        picture->setMaximumSize(QSize(130, 130));
        picture->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(picture);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        userpassward = new QLineEdit(frame);
        userpassward->setObjectName(QString::fromUtf8("userpassward"));
        userpassward->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(userpassward, 1, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(17, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 2, 1, 1);

        usernumber = new QComboBox(frame);
        usernumber->setObjectName(QString::fromUtf8("usernumber"));
        usernumber->setEditable(true);

        gridLayout->addWidget(usernumber, 0, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(17, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_8, 0, 0, 1, 1);

        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setMaximumSize(QSize(15, 15));
        checkBox->setStyleSheet(QString::fromUtf8("QCheckBox::indicator::unchecked{\n"
"    image: url(:/eye/openeye.png);width:15px;height:15px;\n"
"}\n"
"QCheckBox::indicator::checked{\n"
"    image: url(:/eye/closeeye.png);width:15px;height:15px;\n"
"}"));

        gridLayout->addWidget(checkBox, 1, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));

        horizontalLayout_3->addLayout(gridLayout_4);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        login = new QPushButton(frame);
        login->setObjectName(QString::fromUtf8("login"));
        login->setMinimumSize(QSize(93, 28));
        login->setMaximumSize(QSize(93, 28));

        horizontalLayout->addWidget(login);

        regestor = new QPushButton(frame);
        regestor->setObjectName(QString::fromUtf8("regestor"));
        regestor->setMinimumSize(QSize(93, 28));
        regestor->setMaximumSize(QSize(93, 28));

        horizontalLayout->addWidget(regestor);

        cancel = new QPushButton(frame);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setMinimumSize(QSize(93, 28));
        cancel->setMaximumSize(QSize(93, 28));

        horizontalLayout->addWidget(cancel);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_4);


        horizontalLayout_5->addWidget(frame);

        QWidget::setTabOrder(usernumber, userpassward);
        QWidget::setTabOrder(userpassward, login);
        QWidget::setTabOrder(login, regestor);
        QWidget::setTabOrder(regestor, cancel);

        retranslateUi(loginDialog);

        QMetaObject::connectSlotsByName(loginDialog);
    } // setupUi

    void retranslateUi(QDialog *loginDialog)
    {
        loginDialog->setWindowTitle(QApplication::translate("loginDialog", "Dialog", nullptr));
        picture->setText(QString());
        checkBox->setText(QString());
        login->setText(QApplication::translate("loginDialog", "\347\231\273\345\275\225", nullptr));
        regestor->setText(QApplication::translate("loginDialog", "\346\263\250\345\206\214", nullptr));
        cancel->setText(QApplication::translate("loginDialog", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loginDialog: public Ui_loginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
