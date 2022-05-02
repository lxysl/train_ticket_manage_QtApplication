#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->initManagerAccount="123456";
//    this->initManagerPassword="000000";
}

MainWindow::~MainWindow()
{
    delete ui;
}

//QString MainWindow::getInitManagerAccount()const
//{
//    return this->initManagerAccount;
//}

//QString MainWindow::getInitManagerPassword()const
//{
//    return this->initManagerPassword;
//}

//passenger &MainWindow::getNowPassenger()
//{
//    return this->nowPassenger;
//}

//journey &MainWindow::getAJourney()
//{
//    return this->aJourney;
//}

//void MainWindow::changeManagerAccount()
//{

//}

//void MainWindow::changeManagerPassword()
//{

//}

//bool MainWindow::createConnection()
//{
//    this->trainDataBase=QSqlDatabase::addDatabase("QMYSQL");
//    this->trainDataBase.setHostName("localhost");
//    this->trainDataBase.setDatabaseName("mysql");
//    this->trainDataBase.setUserName("root");
//    this->trainDataBase.setPassword("");
//    if(!this->trainDataBase.open()){
//        QMessageBox::warning(0,"错误",this->trainDataBase.lastError().text());
//        return false;
//    }
//    QSqlQuery Data(this->trainDataBase);
//}

//QString passenger::getName()const
//{
//    return this->name;
//}

//QString passenger::getId()const
//{
//    return this->id;
//}
