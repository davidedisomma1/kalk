#include "mainkalk.h"
#include "inputpunto.h"


MainKalk::MainKalk(QWidget *parent) : QWidget(parent),modello(new listModel()),window(new QMainWindow()){

        listaElementi1=new QListView(this);
        listaElementi2=new QListView(this);

        buttonCreaPunto=new QPushButton("Crea punto",this);
        buttonCreaLinea=new QPushButton("Crea linea",this);
        buttonElimina=new QPushButton("Elimina elemento",this);
        buttonModify=new QPushButton("Modifica tag",this);

        layoutGriglia=new QGridLayout(this);
        layoutButton=new QGridLayout();


        listaElementi1->setModel(modello);
        listaElementi2->setModel(modello);

        window->resize(320, 240);
        layoutGriglia->addWidget(listaElementi1,0,0);
        layoutGriglia->addWidget(listaElementi2,0,2);
        layoutButton->addWidget(buttonCreaPunto,0,0);
        layoutButton->addWidget(buttonCreaLinea,1,0);
        layoutButton->addWidget(buttonElimina,2,0);
        layoutButton->addWidget(buttonModify,3,0);
        layoutGriglia->addItem(layoutButton,0,1);

        QObject::connect(buttonCreaPunto,SIGNAL(released()),this,SLOT(creaPunto()));
        QObject::connect(buttonCreaLinea,SIGNAL(released()),this,SLOT(creaLinea()));
        QObject::connect(buttonElimina,SIGNAL(released()),this,SLOT(elimina()));
        QObject::connect(buttonModify,SIGNAL(released()),this,SLOT(cambiaTag()));
}

void MainKalk::creaPunto(){
    inputPunto *inputNuovoPunto=new inputPunto("Crea Punto",this);
    if(inputNuovoPunto->exec()==QDialog::Accepted){
        Punto *nuovoPunto=new Punto(inputNuovoPunto->getInputTag(),inputNuovoPunto->getInputX(),inputNuovoPunto->getInputY());
        modello->inserisciElemento(modello->numeroElementi(),nuovoPunto);
    }
    delete inputNuovoPunto;
}

void MainKalk::creaLinea(){
    Linea* nuovaLinea=new Linea();
    inputPunto *inputPuntoInizio=new inputPunto("Crea Punto Inizio",this);
    if(inputPuntoInizio->exec()==QDialog::Accepted){
        Punto *nuovoPunto=new Punto(inputPuntoInizio->getInputTag(),inputPuntoInizio->getInputX(),inputPuntoInizio->getInputY());
        modello->inserisciElemento(modello->numeroElementi(),nuovoPunto);
        nuovaLinea->setInizio(*nuovoPunto);
        nuovaLinea->setTag(nuovoPunto->getTag());
    }
    delete inputPuntoInizio;
    inputPunto *inputPuntoFine=new inputPunto("Crea Punto Fine",this);
    if(inputPuntoFine->exec()==QDialog::Accepted){
        Punto *nuovoPunto=new Punto(inputPuntoFine->getInputTag(),inputPuntoFine->getInputX(),inputPuntoFine->getInputY());
        modello->inserisciElemento(modello->numeroElementi(),nuovoPunto);
        nuovaLinea->setFine(*nuovoPunto);
        nuovaLinea->setTag(nuovaLinea->getTag()+nuovoPunto->getTag());
    }
    delete inputPuntoFine;
    modello->inserisciElemento(modello->numeroElementi(),nuovaLinea);
}

void MainKalk::elimina(){
    QModelIndexList posizione1=listaElementi1->selectionModel()->selectedIndexes();
    if(!posizione1.isEmpty())
    modello->removeRows(posizione1[0].row(),1);
}


void MainKalk::cambiaTag(){
    QModelIndexList posizione1=listaElementi1->selectionModel()->selectedIndexes();
    if(!posizione1.isEmpty()){
        QString text = QInputDialog::getText(this,tr("Inserisci tag"),tr("Inserisci tag"));
        modello->ritornaElemento(posizione1[0].row())->setTag(text);
        modello->aggiorna(posizione1[0]);
    }

}

