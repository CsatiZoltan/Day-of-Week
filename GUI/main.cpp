#include "../src/gregorian.h"
#include "zellergui.h"
#include <QApplication>
#include <QIcon>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ZellerGUI w;
    w.setWindowIcon(QIcon(":/CalendarIcon.png"));
    w.setWindowTitle("Day of year");
    w.show();

    return a.exec();
}
