/********************************************************************************
** Form generated from reading UI file 'chat.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_4;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *tool;
    QPushButton *minimize;
    QPushButton *maximize;
    QPushButton *close;
    QFrame *info;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *picture;
    QLabel *name;
    QLabel *id;
    QListWidget *contents;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *MyMsg;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *send;
    QPushButton *empty;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(797, 632);
        verticalLayout = new QVBoxLayout(Chat);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(Chat);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        splitter = new QSplitter(frame);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tool = new QHBoxLayout();
        tool->setSpacing(5);
        tool->setObjectName(QString::fromUtf8("tool"));
        minimize = new QPushButton(layoutWidget);
        minimize->setObjectName(QString::fromUtf8("minimize"));
        minimize->setMinimumSize(QSize(20, 20));
        minimize->setMaximumSize(QSize(20, 20));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/tool/minimize.png"), QSize(), QIcon::Normal, QIcon::Off);
        minimize->setIcon(icon);
        minimize->setIconSize(QSize(25, 25));
        minimize->setFlat(true);

        tool->addWidget(minimize);

        maximize = new QPushButton(layoutWidget);
        maximize->setObjectName(QString::fromUtf8("maximize"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(maximize->sizePolicy().hasHeightForWidth());
        maximize->setSizePolicy(sizePolicy);
        maximize->setMinimumSize(QSize(20, 20));
        maximize->setMaximumSize(QSize(20, 20));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/tool/maximize.png"), QSize(), QIcon::Normal, QIcon::Off);
        maximize->setIcon(icon1);
        maximize->setIconSize(QSize(25, 25));
        maximize->setFlat(true);

        tool->addWidget(maximize);

        close = new QPushButton(layoutWidget);
        close->setObjectName(QString::fromUtf8("close"));
        close->setMinimumSize(QSize(20, 20));
        close->setMaximumSize(QSize(20, 20));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/tool/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        close->setIcon(icon2);
        close->setIconSize(QSize(25, 25));
        close->setFlat(true);

        tool->addWidget(close);


        horizontalLayout->addLayout(tool);


        verticalLayout_3->addLayout(horizontalLayout);

        info = new QFrame(layoutWidget);
        info->setObjectName(QString::fromUtf8("info"));
        info->setMinimumSize(QSize(620, 75));
        info->setFrameShape(QFrame::StyledPanel);
        info->setFrameShadow(QFrame::Raised);
        layoutWidget1 = new QWidget(info);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(15, 5, 174, 67));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        picture = new QLabel(layoutWidget1);
        picture->setObjectName(QString::fromUtf8("picture"));
        picture->setMinimumSize(QSize(65, 65));
        picture->setStyleSheet(QString::fromUtf8("background-color: rgb(206, 206, 206);"));

        gridLayout->addWidget(picture, 0, 0, 2, 1);

        name = new QLabel(layoutWidget1);
        name->setObjectName(QString::fromUtf8("name"));
        name->setMinimumSize(QSize(100, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font.setPointSize(11);
        name->setFont(font);

        gridLayout->addWidget(name, 0, 1, 1, 1);

        id = new QLabel(layoutWidget1);
        id->setObjectName(QString::fromUtf8("id"));
        id->setMinimumSize(QSize(100, 20));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font1.setPointSize(10);
        id->setFont(font1);

        gridLayout->addWidget(id, 1, 1, 1, 1);


        verticalLayout_3->addWidget(info);

        contents = new QListWidget(layoutWidget);
        new QListWidgetItem(contents);
        contents->setObjectName(QString::fromUtf8("contents"));

        verticalLayout_3->addWidget(contents);

        splitter->addWidget(layoutWidget);
        layoutWidget2 = new QWidget(splitter);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        MyMsg = new QTextEdit(layoutWidget2);
        MyMsg->setObjectName(QString::fromUtf8("MyMsg"));

        verticalLayout_2->addWidget(MyMsg);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        widget = new QWidget(layoutWidget2);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        send = new QPushButton(widget);
        send->setObjectName(QString::fromUtf8("send"));
        send->setMaximumSize(QSize(80, 30));

        horizontalLayout_2->addWidget(send);

        empty = new QPushButton(widget);
        empty->setObjectName(QString::fromUtf8("empty"));
        empty->setMaximumSize(QSize(80, 30));

        horizontalLayout_2->addWidget(empty);


        horizontalLayout_3->addWidget(widget);


        verticalLayout_2->addLayout(horizontalLayout_3);

        splitter->addWidget(layoutWidget2);

        verticalLayout_4->addWidget(splitter);


        verticalLayout->addWidget(frame);


        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QWidget *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Form", nullptr));
        minimize->setText(QString());
        maximize->setText(QString());
        close->setText(QString());
        picture->setText(QApplication::translate("Chat", "\345\244\264\345\203\217", nullptr));
        name->setText(QApplication::translate("Chat", "name", nullptr));
        id->setText(QApplication::translate("Chat", "id", nullptr));

        const bool __sortingEnabled = contents->isSortingEnabled();
        contents->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = contents->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Chat", "God", nullptr));
        contents->setSortingEnabled(__sortingEnabled);

        send->setText(QApplication::translate("Chat", "\345\217\221\351\200\201", nullptr));
        empty->setText(QApplication::translate("Chat", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
