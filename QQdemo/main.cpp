
#include "clientallwidget.h"
#include "clienttcpsocket.h"
#include "emotionwidget.h"
#include "logindialog.h"
#include "signindialog.h"
#include "testform.h"
#include <QApplication>
#include <showmessage.h>

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
    clientAllWidget A, B;
    A.start();
    //    B.start();
    //    TestForm tt;
    //    tt.show();

    //    EmotionWidget e;
    //    e.show();

    //    showMessage message;
    //    message.show();
    return a.exec();
}
