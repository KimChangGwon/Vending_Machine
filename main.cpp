#include "widget.h"
#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w(NULL);
    w.show();

    return a.exec();
}
