#include "../src/gregorian.h"
#include "zellergui.h"
#include <QApplication>
#include <QTranslator>
#include <QInputDialog>
#include <QIcon>



int main(int argc, char *argv[])
{
    // Initialize application
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/CalendarIcon.png"));

    // Load the required language
    QTranslator t;
    QStringList languages;
    languages << "English" << "Hungarian";
    QString lang = QInputDialog::getItem(NULL, "Select Language", "Language", languages);
    if (lang == "Hungarian")
        t.load(":/hun.qm");
    a.installTranslator(&t);

    // Initialize the windows
    ZellerGUI w;
    w.setWindowIcon(QIcon(":/CalendarIcon.png"));
    w.show();

    return a.exec();
}
