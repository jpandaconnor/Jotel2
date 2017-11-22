#include "setup_testconnection.h"

#include <QSqlDatabase>

Setup_TestConnection::Setup_TestConnection()
{

}

bool Setup_TestConnection::areDetailsValid(QString address, QString dbname, QString username, QString password, int port) {
    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL", "jotel_testconnection");

    database.setHostName(address);
    database.setDatabaseName(dbname);
    database.setUserName(username);
    database.setPassword(password);
    database.setPort(port);

    bool valid = false;

    if(database.open()) {
        valid = true;
        database.close();
    }
    return valid;
}
