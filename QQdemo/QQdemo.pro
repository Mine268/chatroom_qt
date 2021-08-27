QT       += core gui
QT += sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clientallwidget.cpp \
    logindialog.cpp \
    main.cpp \
	signindialog.cpp\
	addfriend.cpp\
	chat.cpp\
	friendlist.cpp\
	setting.cpp\
	toolbutton.cpp

HEADERS += \
    clientallwidget.h \
    logindialog.h \
	signindialog.h\
	addfriend.h\
	chat.h\
	friendlist.h\
	setting.h\
	toolbutton.h

FORMS += \
    logindialog.ui \
	signindialog.ui\
	addfriend.ui\
	chat.ui\
	friendlist.ui\
	setting.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icos.qrc
