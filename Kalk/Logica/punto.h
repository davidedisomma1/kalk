#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>
#include <QtCore/qmath.h>
#include <QMetaType>
#include "tag.h"

class Linea;


class Punto:public Tag{
private:
    double X;
    double Y;
public:
    static Punto origine;

    Punto(QString="A",double=0,double=0);
    Punto(const Punto&)=default;

    double x()const;
    double y()const;

    Linea* operator+(const Punto&) const;
  //  void operator-(const Punto&); da fare
    bool operator==(const Punto&)const;

    Punto* duplicazione(QString)const;
    Punto* simmetricoX(QString)const;
    Punto* simmetricoY(QString)const;
    Punto* simmetricoO(QString)const;
    Linea* joinOrigine()const;
    void traslazione(qreal,qreal);
    double distanzaO()const;

    double distanzaP(const Punto&)const; //da fare
};
Q_DECLARE_METATYPE(Punto*);


std::ostream& operator<<(std::ostream& stream,const Punto& p);

#endif // PUNTO


