#include "punto.h"
#include "linea.h"

Punto Punto::origine("O",0,0);

Punto::Punto(QString s,double cX,double cY):Tag(s),X(cX),Y(cY){
}

double Punto::y()const{
    return Y;
}

double Punto::x()const{
    return X;
}

double Punto::distanzaO()const{
    return (qSqrt(qPow(x(),2)+qPow(y(),2)));
}

Linea* Punto::operator+(const Punto& b) const{
    return new Linea(*this, b);
}


bool Punto::operator==(const Punto& b)const{
    return ((getTag()==b.getTag())&&(x()==b.x())&&(y()==b.y()));
}

/*std::ostream& operator<<(std::ostream& stream,const Punto& p){
    stream<<p.tag.getTag().toStdString()<<'('<<p.x()<<","<<p.y()<<')';
    return stream;
}*/

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

Linea* Punto::joinOrigine()const{
    return new Linea(*this,origine);
}
