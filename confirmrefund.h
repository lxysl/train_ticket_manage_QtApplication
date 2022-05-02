#ifndef CONFIRMREFUND_H
#define CONFIRMREFUND_H

#include <QWidget>
#include <QPushButton>

namespace Ui {
class confirmRefund;
}

class confirmRefund : public QWidget
{
    Q_OBJECT

public:
    explicit confirmRefund(QWidget *parent = 0);
    ~confirmRefund();
    void sendConfirmSignal();
    void sendNConfirmSignal();
signals:
    void confirm();
    void nconfirm();

private:
    Ui::confirmRefund *ui;
};

#endif // CONFIRMREFUND_H
