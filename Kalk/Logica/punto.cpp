#include "punto.h"
#include "linea.h"
#include "spezzata.h"
#include <typeinfo>

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

double Punto::distanzaP(const Punto& p)const{
    return (qSqrt(qPow(x()-p.x(),2)+qPow(y()-p.y(),2)));
}

Tag* Punto::operator+(const Tag& t) const{
    if(typeid(Punto)==typeid(t))
    return new Linea(*this, static_cast<const Punto&>(t));
    if(typeid(Linea)==typeid(t)){
    return t+*this;
    }
    if(typeid(Spezzata)==typeid(t)){
    return t+*this;
    }
}


bool Punto::operator==(const Punto& b)const{
    return ((x()==b.x())&&(y()==b.y()));
}

bool Punto::operator !=(const Punto& b)const{
    return(x()!=b.x()||y()!=b.y());
}

std::ostream& operator<<(std::ostream& stream,const Punto& p){
    stream<<p.getTag().toStdString()<<'('<<p.x()<<","<<p.y()<<')';
    return stream;
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

void Punto::traslazione(double nX,double nY){
    X=X+nX;
    Y=Y+nY;
}


QString Punto::output()const{
    QString stringaOut;
    return stringaOut+getTag()+"("+QString::number(x())+","+QString::number(y())+")";
}


