#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "settingsdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}

void MainWindow::on_actionPoll_triggered()
{
    ui->statusbar->showMessage("Polling...");
}

void MainWindow::on_actionSettings_triggered()
{
    // QMessageBox::information(this, "Configure", "TODO: show configure dialog");
    SettingsDialog *dialog = new SettingsDialog(this);
    dialog->exec();
}

