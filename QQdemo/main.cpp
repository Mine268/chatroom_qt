
#include "clientallwidget.h"
#include "logindialog.h"
#include "signindialog.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

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
    return a.exec();
}
