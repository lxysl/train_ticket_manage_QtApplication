#include "passengerrefund.h"
#include "ui_passengerrefund.h"

passengerrefund::passengerrefund(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::passengerrefund)
{
    ui->setupUi(this);
}

passengerrefund::~passengerrefund()
{
    delete ui;
}
