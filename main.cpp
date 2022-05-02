#include "form.h"
#include "subwindow.h"
#include "triwindow.h"
#include "journey.h"
#include "passenger.h"
#include <QApplication>
#include <QProcess>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QProcess process;
    process.start("D:\mysql-5.7.26-win32\mysql-5.7.26-win32\bin\mysqld.exe");
    QSqlDatabase trainDataBase=QSqlDatabase::addDatabase("QMYSQL");
    trainDataBase.setHostName("localhost");
    trainDataBase.setDatabaseName("mysql");
    trainDataBase.setUserName("root");
    trainDataBase.setPassword("");
    if(!trainDataBase.open()){
        QMessageBox::warning(0,"错误",trainDataBase.lastError().text());
        return false;
    }
    subwindow s;
    triwindow t;
    Form f(&s,&t);
    f.show();
    return a.exec();
}
