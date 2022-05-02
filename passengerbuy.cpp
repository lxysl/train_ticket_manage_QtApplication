#include "passengerbuy.h"
#include "ui_passengerbuy.h"

passengerbuy::passengerbuy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::passengerbuy)
{
    ui->setupUi(this);
}

passengerbuy::~passengerbuy()
{
    delete ui;
}
