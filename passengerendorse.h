#ifndef PASSENGERENDORSE_H
#define PASSENGERENDORSE_H

#include <QWidget>

namespace Ui {
class passengerendorse;
}

class passengerendorse : public QWidget
{
    Q_OBJECT

public:
    explicit passengerendorse(QWidget *parent = 0);
    ~passengerendorse();

private:
    Ui::passengerendorse *ui;
};

#endif // PASSENGERENDORSE_H
