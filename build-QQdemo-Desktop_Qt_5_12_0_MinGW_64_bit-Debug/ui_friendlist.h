/********************************************************************************
** Form generated from reading UI file 'friendlist.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDLIST_H
#define UI_FRIENDLIST_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendList
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *tool;
    QPushButton *minimize;
    QPushButton *maximize;
    QPushButton *close;
    QGridLayout *gridLayout;
    QPushButton *picture;
    QLineEdit *name;
    QLineEdit *id;
    QTreeWidget *treeWidget;
    QLineEdit *searchline;
    QHBoxLayout *tool_2;
    QToolButton *setting;
    QToolButton *add;
    QToolButton *search;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FriendList)
    {
        if (FriendList->objectName().isEmpty())
            FriendList->setObjectName(QString::fromUtf8("FriendList"));
        FriendList->resize(357, 716);
        verticalLayout = new QVBoxLayout(FriendList);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(FriendList);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        tool = new QHBoxLayout();
        tool->setSpacing(5);
        tool->setObjectName(QString::fromUtf8("tool"));
        minimize = new QPushButton(frame);
        minimize->setObjectName(QString::fromUtf8("minimize"));
        minimize->setMinimumSize(QSize(20, 20));
        minimize->setMaximumSize(QSize(20, 20));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/tool/minimize.png"), QSize(), QIcon::Normal, QIcon::Off);
        minimize->setIcon(icon);
        minimize->setIconSize(QSize(25, 25));
        minimize->setFlat(true);

        tool->addWidget(minimize);

        maximize = new QPushButton(frame);
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

        close = new QPushButton(frame);
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


        verticalLayout_2->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        picture = new QPushButton(frame);
        picture->setObjectName(QString::fromUtf8("picture"));
        picture->setMinimumSize(QSize(91, 81));

        gridLayout->addWidget(picture, 0, 0, 2, 1);

        name = new QLineEdit(frame);
        name->setObjectName(QString::fromUtf8("name"));
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe Devanagari"));
        font.setPointSize(24);
        name->setFont(font);
        name->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));

        gridLayout->addWidget(name, 0, 1, 1, 1);

        id = new QLineEdit(frame);
        id->setObjectName(QString::fromUtf8("id"));
        id->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"border-width:0;\n"
"border-style:outset"));

        gridLayout->addWidget(id, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        treeWidget = new QTreeWidget(frame);
        new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(treeWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));

        verticalLayout_2->addWidget(treeWidget);

        searchline = new QLineEdit(frame);
        searchline->setObjectName(QString::fromUtf8("searchline"));

        verticalLayout_2->addWidget(searchline);

        tool_2 = new QHBoxLayout();
        tool_2->setObjectName(QString::fromUtf8("tool_2"));
        setting = new QToolButton(frame);
        setting->setObjectName(QString::fromUtf8("setting"));
        setting->setMaximumSize(QSize(30, 30));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/friendlist/setting.png"), QSize(), QIcon::Normal, QIcon::Off);
        setting->setIcon(icon3);
        setting->setIconSize(QSize(25, 25));

        tool_2->addWidget(setting);

        add = new QToolButton(frame);
        add->setObjectName(QString::fromUtf8("add"));
        add->setMaximumSize(QSize(30, 30));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/friendlist/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        add->setIcon(icon4);
        add->setIconSize(QSize(25, 25));

        tool_2->addWidget(add);

        search = new QToolButton(frame);
        search->setObjectName(QString::fromUtf8("search"));
        search->setMaximumSize(QSize(30, 30));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/friendlist/search.png"), QSize(), QIcon::Normal, QIcon::Off);
        search->setIcon(icon5);
        search->setIconSize(QSize(25, 25));

        tool_2->addWidget(search);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        tool_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(tool_2);


        verticalLayout->addWidget(frame);


        retranslateUi(FriendList);

        QMetaObject::connectSlotsByName(FriendList);
    } // setupUi

    void retranslateUi(QWidget *FriendList)
    {
        FriendList->setWindowTitle(QApplication::translate("FriendList", "Form", nullptr));
        minimize->setText(QString());
        maximize->setText(QString());
        close->setText(QString());
        picture->setText(QApplication::translate("FriendList", "\345\244\264\345\203\217", nullptr));
        name->setText(QApplication::translate("FriendList", "Name", nullptr));
        id->setText(QApplication::translate("FriendList", "Id", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("FriendList", "\346\226\260\345\273\272\345\210\227", nullptr));
        ___qtreewidgetitem->setText(0, QApplication::translate("FriendList", "1", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("FriendList", "God", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(0, QApplication::translate("FriendList", "1", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(0, QApplication::translate("FriendList", "745", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem2->child(1);
        ___qtreewidgetitem4->setText(0, QApplication::translate("FriendList", "45", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem5->setText(0, QApplication::translate("FriendList", "3", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem6->setText(0, QApplication::translate("FriendList", "111", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem6->child(0);
        ___qtreewidgetitem7->setText(0, QApplication::translate("FriendList", "567", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem8->setText(0, QApplication::translate("FriendList", "123", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

        setting->setText(QApplication::translate("FriendList", "\350\256\276\347\275\256", nullptr));
        add->setText(QApplication::translate("FriendList", "\346\267\273\345\212\240", nullptr));
        search->setText(QApplication::translate("FriendList", "\346\220\234\347\264\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FriendList: public Ui_FriendList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDLIST_H
