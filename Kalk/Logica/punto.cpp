#include "punto.h"


Punto::Punto(QString s,qreal x, qreal y):QPointF(x,y),tag(s){}

QString Punto::getTag()const{
    return tag;
}

void Punto::setTag(QString s){
    tag=s;
}

qreal Punto::distanzaO()const{
    return (qSqrt(qPow(x(),2)+qPow(y(),2)));
}

/*Linea* Punto::operator+(const Punto&b) const{
    return new Linea(*this, b);
}*/

bool Punto::operator==(const Punto& b)const{
    return ((tag==b.getTag())&&(x()==b.x())&&(y()==b.y()));
}

std::ostream& operator<<(std::ostream& stream,const Punto& p){
    stream<<p.getTag().toStdString()<<'('<<p.x()<<","<<p.y()<<')';
    return stream;
}

Punto* Punto::duplicazione(QString etichetta)const{
    return new Punto(etichetta, x(), y());
}

Punto* Punto::simmetricoX(QString etichetta)const{
    return new Punto(etichetta,x(),-y());
}

Punto* Punto::simmetricoY(QString etichetta)const{
    return new Punto(etichetta,-x(),y());
}

Punto* Punto::simmetricoO(QString etichetta)const{
    return new Punto(etichetta,-x(),-y());
}

/*Linea* Punto::joinOrigine(QString etichetta)const{
    return new Linea(etichetta,*this,0);
}*/
