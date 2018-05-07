#include "spezzata.h"

Spezzata::Spezzata(const Punto& inizio,const Punto& fine):Linea(inizio,fine){}

const Tag* Spezzata::trovaElemento(QString)const{}

Tag* Spezzata::operator+(const Tag&) const{}

QString Spezzata::output()const{}

Spezzata* Spezzata::simmetricoX(QString)const{}
Spezzata* Spezzata::simmetricoY(QString)const{}
Spezzata* Spezzata::simmetricoO(QString)const{}
void Spezzata::traslazione(double,double){}
double Spezzata::lunghezza()const{}
