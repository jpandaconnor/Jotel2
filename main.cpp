#include "jotel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Jotel w;
    w.show();

    return a.exec();
}
