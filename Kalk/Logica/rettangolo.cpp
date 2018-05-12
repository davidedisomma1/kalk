#include "rettangolo.h"

Rettangolo::Rettangolo(const Punto& a,const Punto& b,const Punto& c,const Punto& d):Spezzata(a,a){
    Spezzata::aggiungiPunto(b);
    Spezzata::aggiungiPunto(c);
    Spezzata::aggiungiPunto(d);
}


Tag* Rettangolo::operator+(const Tag& t) const{
    return Spezzata::operator +(t);
}

QString Rettangolo::output()const{
    return Spezzata::output();
}

Spezzata* Rettangolo::simmetricoX(QString etichetta)const{
    return Spezzata::simmetricoX(etichetta);

}
Spezzata* Rettangolo::simmetricoY(QString etichetta)const{
    return Spezzata::simmetricoY(etichetta);

}
Spezzata* Rettangolo::simmetricoO(QString etichetta)const{
    return Spezzata::simmetricoO(etichetta);
}
void Rettangolo::traslazione(double nX,double nY){
    Spezzata::traslazione(nX,nY);
}
double Rettangolo::lunghezza()const{
    return Spezzata::lunghezza();
}
