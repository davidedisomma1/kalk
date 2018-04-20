#ifndef PUNTO
#define PUNTO

#include <QLineF>
#include <QString>
#include <iostream>
#include <QtCore/qmath.h>
#include <QMetaType>
#include "tag.h"

class Linea: public QLineF{};

class Punto:public Tag{
private:
    double X;
    double Y;
public:

    Punto(QString="A",double=0,double=0);
    Punto(const Punto&)=default;

    double x()const;
    double y()const;

    Linea* operator+(const Punto&) const;
    void operator-(const Punto&);
    bool operator==(const Punto&)const;

    Punto* duplicazione(QString)const;
    Punto* simmetricoX(QString)const;
    Punto* simmetricoY(QString)const;
    Punto* simmetricoO(QString)const;
    Linea* joinOrigine(QString)const;
    void traslazione(qreal,qreal);
    double distanzaO()const;

    double distanzaP(const Punto&)const; //da fare
};
std::ostream& operator<<(std::ostream& stream,const Punto& p);
Q_DECLARE_METATYPE(Punto*);
#endif // PUNTO
