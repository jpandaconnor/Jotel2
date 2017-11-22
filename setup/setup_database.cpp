#include "setup_database.h"
#include "ui_setup_database.h"

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
