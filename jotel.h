#ifndef JOTEL_H
#define JOTEL_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class Jotel;
}

class Jotel : public QMainWindow
{
    Q_OBJECT

public:
    explicit Jotel(QWidget *parent = 0);

    static bool connect_database(QString hostname, QString database_name, QString username, QString password, int port);

    ~Jotel();

private:
    Ui::Jotel *ui;
};

#endif // JOTEL_H
