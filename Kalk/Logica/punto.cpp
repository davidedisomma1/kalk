#include "punto.h"

Punto::Punto(qreal x,qreal y):QPointF(x,y){}

void Punto::setTag(QString s){
    tag=s;
}

std::ostream& Punto::operator<<(std::ostream& os,const Punto& p){
    os<<p.tag<<'('<<p.x()<<','<<p.y()<<')';
    return os;
}
