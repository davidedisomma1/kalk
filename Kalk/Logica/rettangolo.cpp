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
    QString stringaTag,stringaCoord;
    stringaCoord=stringaCoord+" ("+QString::number(getInizio().x())+","+
            QString::number(getInizio().y())+"),";
    for(auto cit=punti.constBegin();cit!=punti.constEnd();++cit){
        stringaCoord=stringaCoord+"("+QString::number(cit->x())+","+
                QString::number(cit->y())+"),";
    }
    return getTag()+stringaCoord.remove(stringaCoord.length()-1,1);
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
    const_cast<Punto&>(getInizio()).traslazione(nX,nY);
    for(auto it=punti.begin();it!=punti.end();++it){
        it->traslazione(nX,nY);
    }
}

double Rettangolo::lunghezza()const{
    return Spezzata::lunghezza();
}

double Rettangolo::area()const{
    return getInizio().distanzaP(punti.first()) * getInizio().distanzaP(punti.last());
}
