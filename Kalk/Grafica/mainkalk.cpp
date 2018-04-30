#include "mainkalk.h"
#include "inputpanelkalk.h"


MainKalk::MainKalk(QWidget *parent) : QWidget(parent){
        window=new QMainWindow;
        listaElementi=new QListView(this);
        buttonCreaPunto=new QPushButton("Crea punto",this);
        buttonCreaLinea=new QPushButton("Crea linea",this);
        buttonElimina=new QPushButton("Elimina elemento",this);
        layoutGriglia=new QGridLayout(this);
        modello=new listModel(listaElementi);

        listaElementi->setModel(modello);

        window->resize(320, 240);
        layoutGriglia->addWidget(listaElementi);
        layoutGriglia->addWidget(buttonCreaPunto);
        layoutGriglia->addWidget(buttonCreaLinea);
        layoutGriglia->addWidget(buttonElimina);

        QObject::connect(buttonCreaPunto,SIGNAL(released()),this,SLOT(creaPunto()));
        QObject::connect(buttonCreaLinea,SIGNAL(released()),this,SLOT(creaLinea()));
        QObject::connect(buttonElimina,SIGNAL(released()),this,SLOT(elimina()));
}

void MainKalk::creaPunto(){
    inputPanelKalk *inputPunto=new inputPanelKalk("Crea Punto",this);
    if(inputPunto->exec()==QDialog::Accepted){
        Punto *nuovoPunto=new Punto(inputPunto->getInputTag(),inputPunto->getInputX(),inputPunto->getInputY());
        modello->inserisciElemento(modello->numeroPunti(),nuovoPunto);
    }
    delete inputPunto;
}

void MainKalk::creaLinea(){
    Linea* nuovaLinea=new Linea();
    inputPanelKalk *inputPuntoInizio=new inputPanelKalk("Crea Punto Inizio",this);
    if(inputPuntoInizio->exec()==QDialog::Accepted){
        Punto *nuovoPunto=new Punto(inputPuntoInizio->getInputTag(),inputPuntoInizio->getInputX(),inputPuntoInizio->getInputY());
        modello->inserisciElemento(modello->numeroPunti(),nuovoPunto);
        nuovaLinea->setInizio(*nuovoPunto);
    }
    delete inputPuntoInizio;
    inputPanelKalk *inputPuntoFine=new inputPanelKalk("Crea Punto Fine",this);
    if(inputPuntoFine->exec()==QDialog::Accepted){
        Punto *nuovoPunto=new Punto(inputPuntoFine->getInputTag(),inputPuntoFine->getInputX(),inputPuntoFine->getInputY());
        modello->inserisciElemento(modello->numeroPunti(),nuovoPunto);
        nuovaLinea->setFine(*nuovoPunto);
    }
    delete inputPuntoFine;
    modello->inserisciElemento(modello->numeroPunti(),nuovaLinea);
}

void MainKalk::elimina(){
    QModelIndexList posizione=listaElementi->selectionModel()->selectedIndexes();
    modello->removeRows(posizione[0].row(),1);

}




