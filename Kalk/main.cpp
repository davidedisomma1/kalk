#include "Grafica/mainwindow.h"
#include <QApplication>
#include "Logica/punto.h"
#include <iostream>
#include <QLabel>
#include<QPushButton>
#include "Grafica/mainkalk.h"
#include <Grafica/dialog.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Dialog m;
    m.show();
    return app.exec();
}
