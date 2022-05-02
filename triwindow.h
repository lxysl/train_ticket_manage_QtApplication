#ifndef TRIWINDOW_H
#define TRIWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QModelIndex>
#include <QList>
#include <QString>


namespace Ui {
class triwindow;
}

class triwindow : public QWidget
{
    Q_OBJECT

public:
    explicit triwindow(QWidget *parent = 0);
    ~triwindow();
    void sendShowSignal();
    QString getInitManagerAccount()const;
    QString getInitManagerPassword()const;
signals:
    void showForm();

private slots:
    void on_addPushButton_clicked();

    void on_deletePushButton_clicked();

    void on_searchPushButton_clicked();

    void on_modifyPushButton_clicked();

    void on_statisticPushButton_clicked();

    void on_startProvince_currentTextChanged(const QString &arg1);

    void on_endProvince_currentTextChanged(const QString &arg1);

    void on_addPushButton_2_clicked();

    void on_deletePushButton_2_clicked();

    void on_recoverPushButton_clicked();

    void on_savePushButton_clicked();

    void on_mannerComboBox_currentTextChanged(const QString &arg1);

    void on_searchPushButton_2_clicked();

    void on_showAll_clicked();

    void on_statisticPushButton_2_clicked();

private:
    Ui::triwindow *ui;
    QSqlTableModel *model;
    QModelIndex index;
    QList<int> deletList;
    QString initManagerAccount;//tri
    QString initManagerPassword;//tri
};

#endif // TRIWINDOW_H
