#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = nullptr);
    ~SettingsDialog();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void jakub_slot(int foo);
    void font_click();

private:
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
