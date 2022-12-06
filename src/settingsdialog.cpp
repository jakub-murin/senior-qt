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
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(jakub_slot(int)));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(font_click()));
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

void SettingsDialog::jakub_slot(int foo)
{
    qDebug() << "hello" << foo;
}

void SettingsDialog::font_click()
{
    qDebug() << ui->pushButton->property("font").value<QFont>().family();
}

