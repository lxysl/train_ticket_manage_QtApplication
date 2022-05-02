#include "dialog.h"
#include "ui_dialog.h"
#include <dialog.h>
#include <qpushbutton.h>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::initDialog(){
    this->vpassengerList=&(MainWindow.passengerList);
    this->vip=&(MainWindow.ip);
}
