#include "rettangolo.h"

Rettangolo::Rettangolo(const Punto& a,const Punto& b,const Punto& c,const Punto& d):Spezzata(a,a){
    Spezzata::aggiungiPunto(b);
    Spezzata::aggiungiPunto(c);
    Spezzata::aggiungiPunto(d);
}

Rettangolo::Rettangolo(const Punto & a):Spezzata(a,a){}



Tag* Rettangolo::operator+(const Tag& t) const{
    return Spezzata::operator +(t);
}

QString Rettangolo::output()const{
    return Spezzata::output();
}

Rettangolo* Rettangolo::simmetricoX(QString etichetta)const{
    Spezzata* s=Spezzata::simmetricoX(etichetta);
    Rettangolo* r=new Rettangolo(s->getInizio());
    for(auto cit=s->punti.constBegin();cit!=s->punti.constEnd();++cit){
        r->Spezzata::aggiungiPunto(*(cit));
    }
    return r;
}
Rettangolo* Rettangolo::simmetricoY(QString etichetta)const{
    Spezzata* s=Spezzata::simmetricoY(etichetta);
    Rettangolo* r=new Rettangolo(s->getInizio());
    for(auto cit=s->punti.constBegin();cit!=s->punti.constEnd();++cit){
        r->Spezzata::aggiungiPunto(*(cit));
    }
    return r;

}
Rettangolo* Rettangolo::simmetricoO(QString etichetta)const{
    Spezzata* s=Spezzata::simmetricoO(etichetta);
    Rettangolo* r=new Rettangolo(s->getInizio());
    for(auto cit=s->punti.constBegin();cit!=s->punti.constEnd();++cit){
        r->Spezzata::aggiungiPunto(*(cit));
    }
    return r;
}

void Rettangolo::traslazione(double nX,double nY){
    Spezzata::traslazione(nX,nY);
}

double Rettangolo::lunghezza()const{
    return Spezzata::lunghezza();
}

double Rettangolo::area()const{
    return getInizio().distanzaP(punti.first()) * getInizio().distanzaP(punti.last());
}
