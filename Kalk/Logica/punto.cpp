#include "punto.h"


Punto::Punto(QString s,qreal x, qreal y):QPointF(x,y),tag(s){}

QString Punto::getTag()const{
    return tag;
}

void Punto::setTag(QString s){
    tag=s;
}

std::ostream& operator<<(std::ostream& stream,const Punto& p){
    stream<<p.getTag().toStdString()<<'('<<p.x()<<","<<p.y()<<')';
    return stream;
}
