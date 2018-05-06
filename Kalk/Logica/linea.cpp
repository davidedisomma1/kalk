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

QString Linea::output()const{
    QString stringaOut;
    return stringaOut+Tag::getTag()+" ("+QString::number(inizio.x())+","+
            QString::number(inizio.y())+"),("+QString::number(fine.x())+","+QString::number(fine.y())+")";
}

const Punto* Linea::trovaElemento(QString s)const{
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
    inizio.traslazione(nX,nY);
    fine.traslazione(nX,nY);
}
