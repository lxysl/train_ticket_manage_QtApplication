#include "form.h"
#include "ui_form.h"

Form::Form(subwindow *s,triwindow *t,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setWindowTitle("登录");
    this->vsubwindow=s;
    this->vtriwindow=t;
    connect(this->vsubwindow,this->vsubwindow->showForm,this,this->showMySelf);
    connect(this->vtriwindow,this->vtriwindow->showForm,this,this->showMySelf);
}

Form::~Form()
{
    delete ui;
}

void Form::showMySelf()
{
    this->vsubwindow->close();
    this->vtriwindow->close();
    this->show();
}

void Form::on_passengerButtonBox_accepted()
{
    QString passengerName=ui->passengerName->text();
    QString passengerAccount=ui->passengerAccount->text();
    bool ok;
    int isText=passengerAccount.toInt(&ok,10);
    passenger aPassenger(passengerName,passengerAccount);
    if(passengerName==""||passengerAccount==""){//用户无输入
        QMessageBox::warning(this,"警告","请输入姓名和身份证号",QMessageBox::Ok);
    }
    else if(!ok){
        QMessageBox::warning(this,"警告","身份证号必须是数字",QMessageBox::Ok);
    }else{
        this->vsubwindow->getModel()->setFilter(QObject::tr("id='%1'").arg(passengerAccount));
        this->vsubwindow->getModel()->select();//只看自己
        if(this->vsubwindow->getModel()->rowCount()!=0){
            QString name = this->vsubwindow->getModel()->record(0).value("name").toString();
            if(name!=passengerName){
                QMessageBox::warning(this,"用户登录","姓名错误",QMessageBox::Cancel);
            }else{
                this->vsubwindow->getNowPassenger()=aPassenger;//设置当前乘客
                this->vsubwindow->setPassengerText();
                QMessageBox::information(this,"用户登录","登录成功",QMessageBox::Ok);
                this->hide();
                vsubwindow->show();
            }
        }else{
        this->vsubwindow->getNowPassenger()=aPassenger;//设置当前乘客
        this->vsubwindow->setPassengerText();
        QMessageBox::information(this,"用户登录","新用户登录成功",QMessageBox::Ok);
        this->hide();
        vsubwindow->show();
        }
    }
}

void Form::on_passengerButtonBox_rejected()
{
    this->close();
}

void Form::on_managerButtonBox_accepted()
{
    QString managerAccount=ui->managerAccount->text();
    QString managerPassword=ui->managerPassword->text();
    if(managerAccount==vtriwindow->getInitManagerAccount()&&managerPassword==vtriwindow->getInitManagerPassword()){
        QMessageBox::information(this,"管理员登录","登录成功",QMessageBox::Ok);
        this->hide();
        vtriwindow->show();
    }else{
        QMessageBox::warning(this,"警告","账号或密码错误",QMessageBox::Ok);
    }
}

void Form::on_managerButtonBox_rejected()
{
    this->close();
}
