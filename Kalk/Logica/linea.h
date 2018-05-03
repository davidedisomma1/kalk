#ifndef LINEA_H
#define LINEA_H

#include "punto.h"

class Spezzata;

class Linea : public Tag{
private:
    Punto inizio,fine;
public:
    Linea(const Punto&,const Punto&);
    Linea(QString="A",double=0,double=0,QString="B",double=0,double=0);

    QString output()const;
    void setInizio(const Punto&);
    void setFine(const Punto&);
    Spezzata* operator+(const Linea&)const;
    Spezzata* operator+(const Punto&)const;
    Spezzata* connect(const Linea&)const;
    Linea* prodottoVettoriale(const Linea&)const;
    Linea* duplicazione(QString,QString) const;
    Linea* simmetricoX(QString,QString)const;
    Linea* simmetricoY(QString,QString)const;
    Linea* simmetricoO(QString,QString)const;
    Punto* puntoMedio()const;

};

#endif // LINEA_H
