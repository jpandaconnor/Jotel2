#ifndef SETUP_TESTCONNECTION_H
#define SETUP_TESTCONNECTION_H

#include <QString>

class Setup_TestConnection
{
public:
    Setup_TestConnection();

    bool areDetailsValid(QString address, QString dbname, QString username, QString password, int port);
};

#endif // SETUP_TESTCONNECTION_H
