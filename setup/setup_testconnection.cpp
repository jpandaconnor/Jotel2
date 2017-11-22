#include "setup_testconnection.h"

#include <QSqlDatabase>

#include <QDebug>
#include <QSqlError>

Setup_TestConnection::Setup_TestConnection()
{

}

bool Setup_TestConnection::areDetailsValid(QString address, QString dbname, QString username, QString password, int port) {
    bool succ = false;

    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL", "jotel_testconnection");

    database.setHostName(address);
    database.setDatabaseName(dbname);
    database.setUserName(username);
    database.setPassword(password);
    database.setPort(port);

    succ = database.open();
    // database.close();

    qDebug() << database.lastError();

    qDebug() << succ;

    return succ;
}
