#ifndef JOURNEY_H
#define JOURNEY_H
#include <QString>

class journey{
public:
    QString id;
    QString name;
    QString startPro;
    QString startCity;
    QString endPro;
    QString endCity;
    QString seat;
    QString startTime;
    int price;
    QString purchaseTime;
public:
    journey() {}
    journey(QString id,QString name,QString startPro,QString startCity,QString endPro,QString endCity,QString seat,QString startTime,int price,QString purchaseTime){
        this->id=id;
        this->name=name;
        this->startPro=startPro;
        this->startCity=startCity;
        this->endPro=endPro;
        this->endCity=endCity;
        this->seat=seat;
        this->startTime=startTime;
        this->price=price;
        this->purchaseTime=purchaseTime;
    }
};



#endif // JOURNEY_H
