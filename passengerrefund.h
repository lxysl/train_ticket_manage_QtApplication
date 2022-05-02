#ifndef PASSENGERREFUND_H
#define PASSENGERREFUND_H

#include <QWidget>

namespace Ui {
class passengerrefund;
}

class passengerrefund : public QWidget
{
    Q_OBJECT

public:
    explicit passengerrefund(QWidget *parent = 0);
    ~passengerrefund();

private:
    Ui::passengerrefund *ui;
};

#endif // PASSENGERREFUND_H
