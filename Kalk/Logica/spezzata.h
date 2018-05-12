#ifndef SPEZZATA_H
#define SPEZZATA_H
#include "Logica/linea.h"
#include <QList>

class Spezzata : public Linea{
private:
    QList<Punto> punti;
public:
    Spezzata(const Punto&,const Punto&);
    Spezzata(const Spezzata&)=default;

    const Tag* trovaElemento(QString)const;

    Tag* operator+(const Tag&) const;
    void aggiungiPunto(const Punto&);

    virtual QString output()const;

    Spezzata* simmetricoX(QString)const;
    Spezzata* simmetricoY(QString)const;
    Spezzata* simmetricoO(QString)const;
    void traslazione(double,double);
    double lunghezza()const;
    Spezzata* chiudiSpezzata(QString)const;
};

#endif // SPEZZATA_H
