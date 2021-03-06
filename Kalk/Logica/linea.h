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
    Linea(const Linea&)=default;

    QString output()const;
    void setInizio(const Punto&);
    void setFine(const Punto&);
    const Punto& getInizio()const;
    const Punto& getFine()const;
    QString getInizioTag()const;
    QString getFineTag()const;
   //     bool operator==(const Punto&)const;
    Tag* operator+(const Tag&) const;

    Linea* simmetricoX(QString)const;
    Linea* simmetricoY(QString)const;
    Linea* simmetricoO(QString)const;
    void traslazione(double,double);

    Punto* puntoMedio(QString)const;
 //   Spezzata* connect(const Linea&)const;
    Linea* sommaVettoriale(const Linea&)const;
    virtual double lunghezza()const;

};

#endif // LINEA_H
