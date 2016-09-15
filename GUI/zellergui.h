#ifndef ZELLERGUI_H
#define ZELLERGUI_H

#include <QMainWindow>

namespace Ui {
class ZellerGUI;
}

class ZellerGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit ZellerGUI(QWidget *parent = 0);
    ~ZellerGUI();

private slots:

    void on_helpPushButton_clicked();

    void on_yearEdit_editingFinished();

    void on_monthEdit_editingFinished();

    void on_dayEdit_editingFinished();

    void on_calendarCombo_currentIndexChanged(int index);

private:
    Ui::ZellerGUI *ui;
};

#endif // ZELLERGUI_H
