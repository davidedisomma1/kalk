#include "linea.h"
#include "spezzata.h"
#include <typeinfo>

Linea::Linea(const Punto& a,const Punto& b):Tag(a.getTag() += b.getTag()),inizio(a),fine(b){}

Linea::Linea(QString t1,double x1,double y1,QString t2,double x2,double y2):Tag(t1+=t2),inizio(t1,x1,y1),fine(t2,x2,y2){}

void Linea::setInizio(const Punto& i){
    inizio=i;
}
void Linea::setFine(const Punto& f){
    fine=f;
}

QString Linea::getInizioTag()const{
    return inizio.getTag();
}

QString Linea::getFineTag()const{
    return fine.getTag();
}

const Punto& Linea::getInizio()const{
    return inizio;
}

const Punto& Linea::getFine() const{
    return fine;
}

QString Linea::output()const{
    QString stringaOut;
    return stringaOut+getTag()+" ("+QString::number(inizio.x())+","+
            QString::number(inizio.y())+"),("+QString::number(fine.x())+","+QString::number(fine.y())+")";
}


Tag* Linea::operator+(const Tag& t)const{
    if(typeid(Punto)==typeid(t)){
    Spezzata* s=new Spezzata(getInizio(), static_cast<const Punto&>(t));
    s->aggiungiPunto(getFine());
    return s;
    }
    if(typeid(Linea)==typeid(t)){
    Spezzata* s=new Spezzata(getInizio(), static_cast<const Linea&>(t).getFine());
    s->aggiungiPunto(getFine());
    s->aggiungiPunto(static_cast<const Linea&>(t).getInizio());
    return s;
    }
    if(typeid(Spezzata)==typeid(t)){
    return t+*this;
    }
}

Linea* Linea::simmetricoX(QString etichetta)const{
    return new Linea(etichetta,inizio.x(),-inizio.y(),"",fine.x(),-fine.y());
}

Linea* Linea::simmetricoY(QString etichetta)const{
    return new Linea(etichetta,-inizio.x(),inizio.y(),"",-fine.x(),fine.y());
}

Linea* Linea::simmetricoO(QString etichetta)const{
    return new Linea(etichetta,-inizio.x(),-inizio.y(),"",-fine.x(),-fine.y());
}

void Linea::traslazione(double nX,double nY){
    inizio.Punto::traslazione(nX,nY);
    fine.Punto::traslazione(nX,nY);
}

double Linea::lunghezza()const{
    return inizio.distanzaP(fine);
}

Punto* Linea::puntoMedio(QString etichetta)const{
    return new Punto(etichetta,((inizio.x()+fine.x())/2),((inizio.y()+fine.y())/2));
}

Linea* Linea::sommaVettoriale(const Linea& l)const{

    Linea vettoreUno(*this);
    vettoreUno.traslazione(l.getFine().x()-vettoreUno.getInizio().x(),l.getFine().y()-vettoreUno.getInizio().y());
    return new Linea(l.getInizio(),vettoreUno.getFine());

}
