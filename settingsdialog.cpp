#include <QMessageBox>
#include <QValidator>
#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    QValidator *validator = new QIntValidator(5, 86400, this);
    ui->pollIntervalInput->setText("60");
    ui->pollIntervalInput->setValidator(validator);

}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::on_buttonBox_accepted()
{
    qInfo("saved");
    accept();
    // QMessageBox::information(this, "Saved", "Your changes to the configuration have been successfully saved (maybe).");
}


void SettingsDialog::on_buttonBox_rejected()
{
    reject();
}

