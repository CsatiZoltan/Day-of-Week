#include <string>
#include <climits>
#include "../src/gregorian.h"

#include <QMessageBox>
#include "zellergui.h"
#include "ui_zellergui.h"

// Local function declarations
std::string helpText();
int checkInput(int input, int lowerBound, int upperBound);

// Global variables
const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const std::string days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", \
                             "Friday", "Saturday", "Sunday"};
int lastWorkingCalendar = 0;

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

void ZellerGUI::on_helpPushButton_clicked()
{
    QMessageBox::information(this, "Help", QString::fromStdString(helpText()));
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
    ui->resultEdit->setText(QString::fromStdString(days[calculatedDay - 1]));
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
    ui->resultEdit->setText(QString::fromStdString(days[calculatedDay - 1]));
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
    ui->resultEdit->setText(QString::fromStdString(days[calculatedDay - 1]));
}


// TODO use char* output in a new .c file to be compatible with the command line
std::string helpText()
{
    std::string help;
    help = "Usage: select the date (year, month and day) you wish\n" \
           " to know on which day of the week it was (or will be)\n" \
           " according to the Gregorian or the Julian calendar that\n" \
           " can be selected on the right. The typed data can be \n" \
           " accepted by pressing Enter or clicking into another field.\n" \
           "\n\n" \
           "Created by\n" \
           "Zoltan Csati" ;
    return help;
}

int checkInput(int input, int lowerBound, int upperBound)
{
    int corrected = input;
    if (input < lowerBound)
        corrected = lowerBound;
    else if (input > upperBound)
        corrected = upperBound;

    return corrected;
}

void ZellerGUI::on_calendarCombo_currentIndexChanged(int index)
{
    if (index == 1) // Julian calendar
    {
        // Throw warning about lack of implementation
        QMessageBox::information(this, "Info", "Calendar not yet implemented.");
        // Change the dropdown menu back to its previous state
        ui->calendarCombo->setCurrentIndex(lastWorkingCalendar);
    }
}
