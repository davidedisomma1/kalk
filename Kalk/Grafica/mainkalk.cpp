#include "mainkalk.h"
#include "inputpanelkalk.h"


MainKalk::MainKalk(QWidget *parent) : QWidget(parent){
        window=new QMainWindow;
        listaElementi1=new QListView(this);
        listaElementi2=new QListView(this);
        buttonCreaPunto=new QPushButton("Crea punto",this);
        buttonCreaLinea=new QPushButton("Crea linea",this);
        buttonElimina=new QPushButton("Elimina elemento",this);
        layoutGriglia=new QGridLayout(this);
        layoutButton=new QGridLayout();
        modello=new listModel();

        listaElementi1->setModel(modello);
        listaElementi2->setModel(modello);

        window->resize(320, 240);
        layoutGriglia->addWidget(listaElementi1,0,0);
        layoutGriglia->addWidget(listaElementi2,0,2);
        layoutButton->addWidget(buttonCreaPunto,0,0);
        layoutButton->addWidget(buttonCreaLinea,1,0);
        layoutButton->addWidget(buttonElimina,2,0);
        layoutGriglia->addItem(layoutButton,0,1);

        QObject::connect(buttonCreaPunto,SIGNAL(released()),this,SLOT(creaPunto()));
        QObject::connect(buttonCreaLinea,SIGNAL(released()),this,SLOT(creaLinea()));
        QObject::connect(buttonElimina,SIGNAL(released()),this,SLOT(elimina()));
}

void MainKalk::creaPunto(){
    inputPanelKalk *inputPunto=new inputPanelKalk("Crea Punto",this);
    if(inputPunto->exec()==QDialog::Accepted){
        Punto *nuovoPunto=new Punto(inputPunto->getInputTag(),inputPunto->getInputX(),inputPunto->getInputY());
        modello->inserisciElemento(modello->numeroElementi(),nuovoPunto);
    }
    delete inputPunto;
}

void MainKalk::creaLinea(){
    Linea* nuovaLinea=new Linea();
    inputPanelKalk *inputPuntoInizio=new inputPanelKalk("Crea Punto Inizio",this);
    if(inputPuntoInizio->exec()==QDialog::Accepted){
        Punto *nuovoPunto=new Punto(inputPuntoInizio->getInputTag(),inputPuntoInizio->getInputX(),inputPuntoInizio->getInputY());
        modello->inserisciElemento(modello->numeroElementi(),nuovoPunto);
        nuovaLinea->setInizio(*nuovoPunto);
    }
    delete inputPuntoInizio;
    inputPanelKalk *inputPuntoFine=new inputPanelKalk("Crea Punto Fine",this);
    if(inputPuntoFine->exec()==QDialog::Accepted){
        Punto *nuovoPunto=new Punto(inputPuntoFine->getInputTag(),inputPuntoFine->getInputX(),inputPuntoFine->getInputY());
        modello->inserisciElemento(modello->numeroElementi(),nuovoPunto);
        nuovaLinea->setFine(*nuovoPunto);
    }
    delete inputPuntoFine;
    modello->inserisciElemento(modello->numeroElementi(),nuovaLinea);
}

void MainKalk::elimina(){
    QModelIndexList posizione1=listaElementi1->selectionModel()->selectedIndexes();
    QModelIndexList posizione2=listaElementi2->selectionModel()->selectedIndexes();
    if(posizione2.isEmpty())
    modello->removeRows(posizione1[0].row(),1);
    if(posizione1.isEmpty())
    modello->removeRows(posizione2[0].row(),1);
}




