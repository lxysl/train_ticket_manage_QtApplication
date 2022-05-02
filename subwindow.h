#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include "triwindow.h"
#include "confirmrefund.h"
#include "journey.h"
#include "passenger.h"

namespace Ui {
class subwindow;
}

class QSqlTableModel;//数据库图表类前置类型声明

class subwindow : public QWidget
{
    Q_OBJECT

public:
    explicit subwindow(QWidget *parent = 0);
    ~subwindow();
    void sendShowSignal();
    void setPassengerText();
    void confirmDelete();
    void nConfirmDelete();
    QSqlTableModel *getModel();
    passenger& getNowPassenger();
signals:
    void showForm();
private slots:
    void on_buy_clicked(bool checked);

    void on_refund_clicked(bool checked);

    void on_endorse_clicked(bool checked);

    void on_startProvince_currentTextChanged(const QString &arg1);

    void on_endProvince_currentTextChanged(const QString &arg1);

    void on_purchaseButton_clicked(bool checked);

    void on_priceShowButton_clicked(bool checked);

    void on_refundButton_clicked(bool checked);

    void on_submitPushButton_clicked();

    void on_CancelPushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

private:
    Ui::subwindow *ui;
    passenger nowPassenger;
    QSqlTableModel *model;//一个数据库表可视化模型
    confirmRefund *confirm;
    QModelIndex index;
};

#endif // SUBWINDOW_H
