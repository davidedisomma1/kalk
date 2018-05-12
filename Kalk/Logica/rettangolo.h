#ifndef RETTANGOLO_H
#define RETTANGOLO_H
#include "Logica/spezzata.h"

class Rettangolo : public Spezzata
{
public:
    Rettangolo(const Punto&,const Punto&,const Punto&,const Punto&);
    Rettangolo(const Rettangolo&)=default;


        Tag* operator+(const Tag&) const;
        void aggiungiPunto(const Punto&);
        bool trovaPunto(QString );

        virtual QString output()const;

        Spezzata* simmetricoX(QString)const;
        Spezzata* simmetricoY(QString)const;
        Spezzata* simmetricoO(QString)const;
        void traslazione(double,double);
        double lunghezza()const;

};

#endif // RETTANGOLO_H
