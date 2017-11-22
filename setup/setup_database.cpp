#include "setup_database.h"
#include "ui_setup_database.h"

#include <QMessageBox>

#include <QCloseEvent>

Setup_Database::Setup_Database(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Setup_Database)
{
    ui->setupUi(this);
}

Setup_Database::~Setup_Database()
{
    delete ui;
}

void Setup_Database::closeEvent(QCloseEvent *event) {
    QMessageBox::StandardButton confirmation = QMessageBox::question(
                this, "Exit", tr("Are you sure you want to exit?"),
                QMessageBox::Cancel | QMessageBox::Ok);

    if(confirmation != QMessageBox::Ok) {
        event->ignore();
    } else {
        event->accept();
        QApplication::quit();
    }
}

void Setup_Database::on_buttons_rejected() {
    QMessageBox::StandardButton confirmation = QMessageBox::question(
                this, "Exit", tr("Cancelling this setup will close Jotel. Continue?"),
                QMessageBox::Cancel | QMessageBox::Ok);

    if(confirmation != QMessageBox::Ok) {
        event->ignore();
    } else {
        event->accept();
        QApplication::quit();
    }
}

void Setup_Database::on_buttons_accepted() {
    // Start the connection check here
}
