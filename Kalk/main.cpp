#include "Grafica/mainwindow.h"
#include <QApplication>
#include "Logica/punto.h"
#include <iostream>
#include <QLabel>
#include<QPushButton>
#include "Grafica/mainkalk.h"

using std::cout;
using std::endl;
int main(int argc, char *argv[])
{


    Punto punto("ciao",2,2),vuoto;
    cout<<punto<<endl;
    punto.setTag("hello");
    cout<<punto<<endl;
    qreal ipotenusa=punto.distanzaO();
    cout<<ipotenusa<<endl;

    QApplication app(argc, argv);
    MainKalk m;
    m.show();
    return app.exec();
}
