#include "linea.h"

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

Punto Linea::getInizio()const{
    return inizio;
}

Punto Linea::getFine() const{
    return fine;
}

QString Linea::output()const{
    QString stringaOut;
    return stringaOut+Tag::getTag()+" ("+QString::number(inizio.x())+","+
            QString::number(inizio.y())+"),("+QString::number(fine.x())+","+QString::number(fine.y())+")";
}

const Tag* Linea::trovaElemento(QString s)const{
    if(inizio.getTag()==s) return &inizio;
    if(fine.getTag()==s) return &fine;
    return 0;
}

Tag* Linea::operator+(const Tag& t)const{
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
    Linea vettoreDue(l);
    vettoreUno.traslazione(vettoreDue.getInizio().x()-vettoreUno.getInizio().x(),vettoreDue.getFine().y()-vettoreUno.getInizio().y());
    return new Linea(vettoreDue.getInizio(),vettoreUno.getFine());
}
