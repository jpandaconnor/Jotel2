#include "setup_database.h"
#include "ui_setup_database.h"

// Database connection test
#include "setup/setup_testconnection.h"

#include <QMessageBox>
#include <QString>

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

void Setup_Database::validateInput() {
    QString ts_ip;
    QString ts_dbname;
    QString ts_user;
    QString ts_password;

    int ts_port;

    // If no address is put in, we'll get the placeholder (Normally "localhost")
    if(ui->addressLineEdit->text().isEmpty()) {
        ts_ip = ui->addressLineEdit->placeholderText();
    } else {
        ts_ip = ui->addressLineEdit->text();
    }

    // Database name
    if(ui->databaseNameLineEdit->text().isEmpty()) {
        ts_dbname = ui->databaseNameLineEdit->placeholderText();
    } else {
        ts_dbname = ui->databaseNameLineEdit->text();
    }

    // Username
    if(ui->userLineEdit->text().isEmpty()) {
        ts_user = ui->userLineEdit->placeholderText();
    } else {
        ts_user = ui->userLineEdit->text();
    }

    // Port
    QRegExp re("\\d*"); // Verifies ints
    if(!ui->portLineEdit->text().isEmpty()) {
        if(!re.exactMatch(ui->portLineEdit->text())) {
            QMessageBox::warning(this, "Invalid Port", tr("Please enter a valid port number"));
            return;
        } else {
            ts_port = ui->portLineEdit->text().toInt();
        }
    } else {
        ts_port = ui->portLineEdit->placeholderText().toInt();
    }

    // Password last since we have some special checks for that
    if(ui->passwordLineEdit->text().isEmpty()) {
        QMessageBox::StandardButton nopasswordconfirm = QMessageBox::question(
                    this, "No Password", tr("Most databases won't connect without a password. Are you sure you want to continue"),
                    QMessageBox::Yes | QMessageBox::No);

        if(nopasswordconfirm == QMessageBox::Yes) {
            ts_password = "";
        } else {
            return;
        }
    } else {
        ts_password = ui->passwordLineEdit->text();
    }

    Setup_TestConnection* test_connection = new Setup_TestConnection();

    if(test_connection->areDetailsValid(ts_ip, ts_dbname, ts_user, ts_password, ts_port)) {
        greyOut();
        QMessageBox::StandardButton info = QMessageBox::information(
                    this, "Connted", tr("Successfully conneted to the database"), QMessageBox::Ok);


        // Delete the pointer
        delete test_connection;
        test_connection = NULL;

        // Open the connection
    } else {
        greyIn();
        QMessageBox::critical(this, "Database error",
                              tr("Jotel could not connect to the database. Please check the details and try again"));
    }

    delete test_connection;
    test_connection = NULL;
}

// To stop users editing data whilst it attempts to connect to the databse
void Setup_Database::greyIn() {
    ui->addressLineEdit->setEnabled(true);
    ui->databaseNameLineEdit->setEnabled(true);
    ui->userLineEdit->setEnabled(true);
    ui->passwordLineEdit->setEnabled(true);
    ui->portLineEdit->setEnabled(true);
}

void Setup_Database::greyOut() {
    ui->addressLineEdit->setEnabled(false);
    ui->databaseNameLineEdit->setEnabled(false);
    ui->userLineEdit->setEnabled(false);
    ui->passwordLineEdit->setEnabled(false);
    ui->portLineEdit->setEnabled(false);
}

void Setup_Database::on_buttons_rejected() {
    QMessageBox::StandardButton confirmation = QMessageBox::question(
                this, "Exit", tr("Cancelling this setup will close Jotel. Continue?"),
                QMessageBox::Cancel | QMessageBox::Ok);

    if(confirmation != QMessageBox::Cancel) {
        QApplication::quit();
    }
}

void Setup_Database::on_buttons_accepted() {
    validateInput();
}
