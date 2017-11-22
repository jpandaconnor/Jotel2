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

    static void connect_database();

    ~Jotel();

private:
    Ui::Jotel *ui;
};

#endif // JOTEL_H
