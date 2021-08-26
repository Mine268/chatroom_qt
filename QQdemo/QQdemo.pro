QT       += core gui
QT += sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    logindialog.cpp \
    main.cpp \
    mydialog.cpp \
    myqtcpsever.cpp \
    signindialog.cpp \
    testdialog.cpp \
    widget.cpp

HEADERS += \
    logindialog.h \
    mydialog.h \
    myqtcpsever.h \
    signindialog.h \
    testdialog.h \
    widget.h

FORMS += \
    logindialog.ui \
    mydialog.ui \
    signindialog.ui \
    testdialog.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
