#include "punto.h"
#include <QDataStream>

Punto::Punto(qreal x,qreal y):QPointF(x,y){}

QString Punto::getTag()const{
    return tag;
}

void Punto::setTag(QString s){
    tag=s;
}

QDataStream& operator<<(QDataStream& stream,const Punto& p){
    stream<<p.tag<<'('<<p.x()<<','<<p.y()<<')';
    return stream;
}
