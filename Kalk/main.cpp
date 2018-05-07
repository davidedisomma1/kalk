#include "Grafica/mainwindow.h"
#include <QApplication>
#include "Logica/punto.h"
#include <iostream>
#include <QLabel>
#include<QPushButton>
#include "Grafica/mainkalk.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainKalk m;
    m.show();
    return app.exec();
}
