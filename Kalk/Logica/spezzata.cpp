#include "spezzata.h"

Spezzata::Spezzata(const Punto& inizio,const Punto& fine):Linea(inizio,fine),punti(){}

const Tag* Spezzata::trovaElemento(QString t)const{
    if(getInizioTag()==t) return &getInizio();
    for(auto cit=punti.constBegin();cit!=punti.constEnd();++cit){
        if(cit->getTag()==t) return &(*cit);
    }
    if(getFineTag()==t) return &getFine();
    return 0;
}

Tag* Spezzata::operator+(const Tag&) const{}

QString Spezzata::output()const{
    QString stringaTag,stringaCoord;
    stringaTag=stringaTag+getInizioTag();
    stringaCoord=stringaCoord+" ("+QString::number(getInizio().x())+","+
            QString::number(getInizio().y())+"),";
    for(auto cit=punti.constBegin();cit!=punti.constEnd();++cit){
        stringaTag=stringaTag+cit->getTag();
        stringaCoord=stringaCoord+"("+QString::number(cit->x())+","+
                QString::number(cit->y())+"),";
    }
    stringaTag=stringaTag+getFineTag()+" ";
    stringaCoord=stringaCoord+"("+QString::number(getFine().x())+","+QString::number(getFine().y())+")";
    return stringaTag+stringaCoord;
}

Spezzata* Spezzata::simmetricoX(QString etichetta)const{
    Spezzata* s=new Spezzata(*(getInizio().simmetricoX(etichetta)),*(getFine().simmetricoX("")));
    for(auto cit=punti.constBegin();cit!=punti.constEnd();++cit){
        s->aggiungiPunto(*(cit->simmetricoX("")));
    }
    return s;
}
Spezzata* Spezzata::simmetricoY(QString etichetta)const{
    Spezzata* s=new Spezzata(*(getInizio().simmetricoY(etichetta)),*(getFine().simmetricoY("")));
    for(auto cit=punti.constBegin();cit!=punti.constEnd();++cit){
        s->aggiungiPunto(*(cit->simmetricoY("")));
    }
    return s;
}
Spezzata* Spezzata::simmetricoO(QString etichetta)const{
    Spezzata* s=new Spezzata(*(getInizio().simmetricoO(etichetta)),*(getFine().simmetricoO("")));
    for(auto cit=punti.constBegin();cit!=punti.constEnd();++cit){
        s->aggiungiPunto(*(cit->simmetricoO("")));
    }
    return s;
}
void Spezzata::traslazione(double nX,double nY){
    const_cast<Punto&>(getInizio()).traslazione(nX,nY);
    const_cast<Punto&>(getFine()).traslazione(nX,nY);
    for(auto it=punti.begin();it!=punti.end();++it){
        it->traslazione(nX,nY);
    }
}
double Spezzata::lunghezza()const{
    double somma=0;
    if(punti.length()==0) return getInizio().distanzaP(getFine());
    if(punti.length()==1) return getInizio().distanzaP(punti.first()) + punti.first().distanzaP(getFine());
    else{
        somma=somma+getInizio().distanzaP(punti.first());
        for(auto cit=punti.constBegin();cit!=punti.constEnd()-1;++cit){
            somma=somma+cit->distanzaP(*(++cit));
        }
        somma=somma+getFine().distanzaP(punti.last());
        return somma;
    }
}

void Spezzata::aggiungiPunto(const Punto& p){
    punti.push_back(p);
}
