#ifndef PASSENGERBUY_H
#define PASSENGERBUY_H

#include <QWidget>

namespace Ui {
class passengerbuy;
}

class passengerbuy : public QWidget
{
    Q_OBJECT

public:
    explicit passengerbuy(QWidget *parent = 0);
    ~passengerbuy();

private:
    Ui::passengerbuy *ui;
};

#endif // PASSENGERBUY_H
