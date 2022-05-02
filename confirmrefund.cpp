#include "confirmrefund.h"
#include "ui_confirmrefund.h"

confirmRefund::confirmRefund(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::confirmRefund)
{
    ui->setupUi(this);
    setWindowTitle("确认退票");
    connect(ui->yesPushButton,QPushButton::clicked,this,this->sendConfirmSignal);
    connect(ui->noPushButton,QPushButton::clicked,this,this->sendNConfirmSignal);
}

confirmRefund::~confirmRefund()
{
    delete ui;
}

void confirmRefund::sendConfirmSignal()
{
    emit confirm();
}

void confirmRefund::sendNConfirmSignal()
{
    emit nconfirm();
}
