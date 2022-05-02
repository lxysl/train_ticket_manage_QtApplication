#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>

#include <qstring.h>
#include <QMap>
#include <QList>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "journey.h"
#include "passenger.h"


namespace Ui {
class MainWindow;
}

class QSqlTableModel;//数据库图表类前置类型声明

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //QString getInitManagerAccount()const;
    //QString getInitManagerPassword()const;
    //passenger& getNowPassenger();
    //journey& getAJourney();
    //void changeManagerAccount();
    //void changeManagerPassword();
    //bool createConnection();
private slots:

private:
    //QString initManagerAccount;//tri
    //QString initManagerPassword;//tri
    Ui::MainWindow *ui;
    //passenger nowPassenger;//subwindow
    //journey aJourney;
    //QSqlDatabase trainDataBase;//form
};

#endif // MAINWINDOW_H
