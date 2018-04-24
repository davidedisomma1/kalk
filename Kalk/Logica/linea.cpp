#include "linea.h"

Linea::Linea(const Punto& a,const Punto& b):Tag(a.getTag() += b.getTag()),inizio(a),fine(b){}

Linea::Linea(QString t1,double x1,double y1,QString t2,double x2,double y2):Tag(t1+=t2),inizio(t1,x1,y1),fine(t2,x2,y2){}
