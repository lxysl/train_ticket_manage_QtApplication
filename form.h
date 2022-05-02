#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QList>
#include <QMessageBox>
#include "subwindow.h"
#include "triwindow.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(subwindow *s,triwindow *t,QWidget *parent = 0);
    ~Form();
    void showMySelf();
private slots:

    void on_passengerButtonBox_accepted();

    void on_passengerButtonBox_rejected();

    void on_managerButtonBox_accepted();

    void on_managerButtonBox_rejected();

private:
    Ui::Form *ui;
    subwindow *vsubwindow;
    triwindow *vtriwindow;
};

#endif // FORM_H
