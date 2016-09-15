#include "../src/gregorian.h"
#include "zellergui.h"
#include <QApplication>





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ZellerGUI w;
    w.show();
    int result = gregorian(2016,8,21);
    return a.exec();
}
