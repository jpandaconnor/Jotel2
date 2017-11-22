#include "jotel.h"
#include "ui_jotel.h"

// Crypto

#include "crypto/simplecrypt.h"

// Database setup
#include "setup/setup_database.h"

#include <QCoreApplication>
#include <QSettings>

#include <QSqlDatabase>
#include <QString>

#include <QDebug>

Jotel::Jotel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Jotel)
{
    ui->setupUi(this);

    QCoreApplication::setOrganizationName("JPanda");
    QCoreApplication::setOrganizationDomain("jpanda.org");
    QCoreApplication::setApplicationName("Jotel");
    QCoreApplication::setApplicationVersion("1.0");

    // Probably change this into another file later on
    QSettings settings;

    if(settings.value("database/host").toInt() == 0) {
        qDebug() << "Does not exist";

        Setup_Database* database_setup = new Setup_Database();
        database_setup->setModal(true);
        database_setup->show();

        // There is nothing set up in here
    } else {
        QString host = settings.value("database/host").toString();
        QString dbname = settings.value("database/dbname").toString();
        QString user = settings.value("database/user").toString();
        QString password = settings.value("database/password").toString();
        int port = settings.value("database/port").toInt();

        // Decrypt down here

        // SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023));
        // QString result = crypto.encryptToString(testString);
    }

    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL", "jotel_connection");

    database.setHostName("localhost");
    database.setDatabaseName("jotel");
    database.setUserName("root");
    database.setPassword("teamo17october2014");
    database.setPort(3306);

    database.open();
}

Jotel::~Jotel()
{
    delete ui;
}
