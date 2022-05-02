#include "passengerendorse.h"
#include "ui_passengerendorse.h"

passengerendorse::passengerendorse(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::passengerendorse)
{
    ui->setupUi(this);
}

passengerendorse::~passengerendorse()
{
    delete ui;
}
