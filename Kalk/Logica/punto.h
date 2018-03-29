#ifndef PUNTO
#define PUNTO

#include <QPointF>
#include <QLineF>
#include <QString>
#include <iostream>
#include <QtCore/qmath.h>
#include <QMetaType>

class Linea: public QLineF{};

class Punto: public QPointF{
private:
    QString tag;
public:

    Punto(QString="A",qreal=0,qreal=0);
    Punto(const Punto&)=default;

    Linea* operator+(const Punto&) const;
    void operator-(const Punto&);
    bool operator==(const Punto&)const;

    Punto* duplicazione(QString)const;
    Punto* simmetricoX(QString)const;
    Punto* simmetricoY(QString)const;
    Linea* joinOrigine(QString)const;
    void traslazione(qreal,qreal);
    qreal distanzaP(const Punto&)const;
    qreal distanzaO()const;
    void setTag(QString);
    QString getTag()const;
};
std::ostream& operator<<(std::ostream& stream,const Punto& p);
    Q_DECLARE_METATYPE(Punto);
#endif // PUNTO
