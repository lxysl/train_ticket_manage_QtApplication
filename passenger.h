#ifndef PASSENGER_H
#define PASSENGER_H
#include <QString>

class passenger{
private:
    QString name;
    QString id;
public:
    passenger(){}
    passenger(QString name,QString id){
        this->name=name;
        this->id=id;
    }
    QString getName() const{
        return this->name;
    }
    QString getId() const{
        return this->id;
    }
};

#endif // PASSENGER_H
