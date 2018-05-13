#ifndef RETTANGOLO_H
#define RETTANGOLO_H
#include "Logica/spezzata.h"

class Rettangolo : public Spezzata
{
public:
    Rettangolo(const Punto& ,const Punto& ,const Punto& ,const Punto& );
    Rettangolo(const Punto& ,const Punto& );
    Rettangolo(const Punto& );
    Rettangolo(const Rettangolo&)=default;


        Tag* operator+(const Tag&) const;
        void aggiungiPunto(const Punto&);

        virtual QString output()const;

        Rettangolo* simmetricoX(QString)const;
        Rettangolo* simmetricoY(QString)const;
        Rettangolo* simmetricoO(QString)const;
        void traslazione(double,double);
        double lunghezza()const;
        double area()const;

};

#endif // RETTANGOLO_H
