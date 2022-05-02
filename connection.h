#ifndef CONNECTION_H
#define CONNECTION_H
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

static bool createConnection(){
    QSqlDatabase database=QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setDatabaseName("mysql");
    database.setUserName("root");
    database.setPassword("lxyL764139720");
    if(!database.open()){
        QMessageBox::warning(0,"错误",database.lastError().text());
        return false;
    }else{
        QMessageBox::information(0,"数据库","成功");
    }// 如果 MySQL 数据库中已经存在同名的表， 那么下面的代码不会执行
    QSqlQuery trainData(database);// 使数据库支持中文
    trainData.exec("SET NAMES'Latin1'");
    return true;
}

#endif // CONNECTION_H
