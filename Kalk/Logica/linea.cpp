#include "linea.h"

Linea::Linea(const Punto& a,const Punto& b):Tag(a.getTag() += b.getTag()),inizio(a),fine(b){}

void Linea::setInizio(const Punto& i){
    inizio=i;
}
void Linea::setFine(const Punto& f){
    fine=f;
}


Linea::Linea(QString t1,double x1,double y1,QString t2,double x2,double y2):Tag(t1+=t2),inizio(t1,x1,y1),fine(t2,x2,y2){}

QString Linea::output()const{
    QString stringaOut;
    return stringaOut+(inizio.getTag())+(fine.getTag())+" ("+QString::number(inizio.x())+","+
            QString::number(inizio.y())+"),("+QString::number(fine.x())+","+QString::number(fine.y())+")";
}

