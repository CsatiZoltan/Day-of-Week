#include <string>
#include <climits>
#include "../src/gregorian.h"

#include <QMessageBox>
#include <QString>
#include "zellergui.h"
#include "ui_zellergui.h"


// Local function declarations
QString helpText();
int checkInput(int input, int lowerBound, int upperBound);

// Global variables
const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char * const days[7] = {
    QT_TRANSLATE_NOOP("Weekdays", "Monday"),
    QT_TRANSLATE_NOOP("Weekdays", "Tuesday"),
    QT_TRANSLATE_NOOP("Weekdays", "Wednesday"),
    QT_TRANSLATE_NOOP("Weekdays", "Thursday"),
    QT_TRANSLATE_NOOP("Weekdays", "Friday"),
    QT_TRANSLATE_NOOP("Weekdays", "Saturday"),
    QT_TRANSLATE_NOOP("Weekdays", "Sunday")
}; // idea is taken from https://forum.qt.io/topic/73971/translation-does-not-work-when-the-text-of-qlineedit-is-modified
int lastWorkingCalendar = 0;



// Set up the user interface
ZellerGUI::ZellerGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ZellerGUI)
{
    ui->setupUi(this);
}

ZellerGUI::~ZellerGUI()
{
    delete ui;
}



// Implement callback functions
void ZellerGUI::on_helpPushButton_clicked()
{
    QMessageBox::information(this, tr("Help"), helpText());
}


void ZellerGUI::on_yearEdit_editingFinished()
{
    // Correct the possibly incorrect data
    int givenYear = ui->yearEdit->text().toInt();
    int correctedYear = checkInput(givenYear, 1582, INT_MAX);
    ui->yearEdit->setText(QString::number(correctedYear));

    // Calculate the day of the week
    int calculatedDay = gregorian(ui->yearEdit->text().toInt(), \
                                  ui->monthEdit->text().toInt(), \
                                  ui->dayEdit->text().toInt());
    QString day = QCoreApplication::translate("Weekdays", days[calculatedDay - 1]);
    ui->resultEdit->setText(day);
}


void ZellerGUI::on_monthEdit_editingFinished()
{
    // Correct the possibly incorrect data
    int givenMonth = ui->monthEdit->text().toInt();
    int correctedMonth = checkInput(givenMonth, 1, 12);
    ui->monthEdit->setText(QString::number(correctedMonth));

    // Also modify the day if the altered month contains less days
    int givenDay = ui->dayEdit->text().toInt();
    int lastDay = monthDays[ui->monthEdit->text().toInt() - 1];
    int correctedDay = checkInput(givenDay, 1, lastDay);
    ui->dayEdit->setText(QString::number(correctedDay));

    // Calculate the day of the week
    int calculatedDay = gregorian(ui->yearEdit->text().toInt(), \
                                  ui->monthEdit->text().toInt(), \
                                  ui->dayEdit->text().toInt());
    QString day = QCoreApplication::translate("Weekdays", days[calculatedDay - 1]);
    ui->resultEdit->setText(day);
}


void ZellerGUI::on_dayEdit_editingFinished()
{
    // Correct the possibly incorrect data
    int givenDay = ui->dayEdit->text().toInt();
    int lastDay = monthDays[ui->monthEdit->text().toInt() - 1];
    int correctedDay = checkInput(givenDay, 1, lastDay);
    ui->dayEdit->setText(QString::number(correctedDay));

    // Calculate the day of the week
    int calculatedDay = gregorian(ui->yearEdit->text().toInt(), \
                                  ui->monthEdit->text().toInt(), \
                                  ui->dayEdit->text().toInt());
    QString day = QCoreApplication::translate("Weekdays", days[calculatedDay - 1]);
    ui->resultEdit->setText(day);
}


QString helpText()
{
    QString help;
    help = QCoreApplication::tr("Usage: select the date (year, month and day) you wish\n" \
           " to know on which day of the week it was (or will be)\n" \
           " according to the Gregorian or the Julian calendar that\n" \
           " can be selected on the right. The typed data can be \n" \
           " accepted by pressing Enter or clicking into another field.\n" \
           "\n\n" \
           "Created by\n" \
           "Zoltan Csati");
    return help;
}


void ZellerGUI::on_calendarCombo_currentIndexChanged(int index)
{
    if (index == 1) // Julian calendar
    {
        // Throw warning about lack of implementation
        QMessageBox::information(this, tr("Info"), tr("Calendar not yet implemented."));
        // Change the dropdown menu back to its previous state
        ui->calendarCombo->setCurrentIndex(lastWorkingCalendar);
    }
}


// Input checking used in several callback functions
int checkInput(int input, int lowerBound, int upperBound)
{
    int corrected = input;
    if (input < lowerBound)
        corrected = lowerBound;
    else if (input > upperBound)
        corrected = upperBound;

    return corrected;
}
