#ifndef SETUP_DATABASE_H
#define SETUP_DATABASE_H

#include <QDialog>

namespace Ui {
class Setup_Database;
}

class Setup_Database : public QDialog
{
    Q_OBJECT

public:
    explicit Setup_Database(QWidget *parent = 0);
    ~Setup_Database();

private slots:
    void on_buttons_rejected();
    void on_buttons_accepted();

private:
    Ui::Setup_Database *ui;

    void closeEvent(QCloseEvent* event);
};

#endif // SETUP_DATABASE_H
