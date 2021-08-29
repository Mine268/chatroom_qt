
#include "clientallwidget.h"
#include "clienttcpsocket.h"
#include "logindialog.h"
#include "signindialog.h"
#include "testform.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<QList<struct user>>("QList< struct user>");
    qRegisterMetaType<struct chat_msg>("struct chat_msg");
    //    loginDialog t;
    //    t.show();
    //    Widget w;
    //    w.show();
    //    signinDialog s;
    //    s.show();
    //    TestDialog T;
    //    T.show();
    clientAllWidget A;
    A.start();
    //    TestForm tt;
    //    tt.show();
    return a.exec();
}
