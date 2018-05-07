#ifndef SPEZZATA_H
#define SPEZZATA_H
#include "Logica/linea.h"
#include <QList>

class Spezzata : public Linea{
private:
    QList<Punto> punti;
public:
    Spezzata(const Punto&,const Punto&);
};

#endif // SPEZZATA_H
