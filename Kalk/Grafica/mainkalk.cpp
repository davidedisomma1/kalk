#include "mainkalk.h"
#include "inputpunto.h"


MainKalk::MainKalk(QWidget *parent) : QWidget(parent),modello(new listModel()),window(new QMainWindow()){

        listaElementi1=new QListView(this);
        listaElementi2=new QListView(this);

        buttonCreaPunto=new QPushButton("Crea punto",this);
        buttonCreaLinea=new QPushButton("Crea linea",this);
        buttonElimina=new QPushButton("Elimina elemento",this);
        buttonModifyTag=new QPushButton("Modifica tag",this);
        buttonSimmetricoX=new QPushButton("Simmetrico X",this);
        buttonSimmetricoY=new QPushButton("Simmetrico Y",this);
        buttonSimmetricoO=new QPushButton("Simmetrico Origine",this);
        buttonTraslazione=new QPushButton("Traslazione",this);

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
        layoutButton->addWidget(buttonModifyTag,3,0);
        layoutButton->addWidget(buttonSimmetricoO,4,0);
        layoutButton->addWidget(buttonSimmetricoX,5,0);
        layoutButton->addWidget(buttonSimmetricoY,6,0);
        layoutButton->addWidget(buttonTraslazione,7,0);
        layoutGriglia->addItem(layoutButton,0,1);

        QObject::connect(buttonCreaPunto,SIGNAL(released()),this,SLOT(creaPunto()));
        QObject::connect(buttonCreaLinea,SIGNAL(released()),this,SLOT(creaLinea()));
        QObject::connect(buttonElimina,SIGNAL(released()),this,SLOT(elimina()));
        QObject::connect(buttonModifyTag,SIGNAL(released()),this,SLOT(cambiaTag()));
        QObject::connect(buttonSimmetricoO,SIGNAL(released()),this,SLOT(simmetriaO()));
        QObject::connect(buttonSimmetricoX,SIGNAL(released()),this,SLOT(simmetriaX()));
        QObject::connect(buttonSimmetricoY,SIGNAL(released()),this,SLOT(simmetriaY()));
  //      QObject::connect(buttonTraslazione,SIGNAL(released()),this,SLOT(traslazione()));
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

void MainKalk::simmetriaO(){
    QModelIndexList posizione1=listaElementi1->selectionModel()->selectedIndexes();
    if(!posizione1.isEmpty()){
        QString text = QInputDialog::getText(this,tr("Inserisci tag"),tr("Inserisci tag"));
        modello->inserisciElemento(modello->numeroElementi(),modello->ritornaElemento(posizione1[0].row())->simmetricoO(text));
    }

}

void MainKalk::simmetriaX(){
    QModelIndexList posizione1=listaElementi1->selectionModel()->selectedIndexes();
    if(!posizione1.isEmpty()){
        QString text = QInputDialog::getText(this,tr("Inserisci tag"),tr("Inserisci tag"));
        modello->inserisciElemento(modello->numeroElementi(),modello->ritornaElemento(posizione1[0].row())->simmetricoX(text));
    }

}

void MainKalk::simmetriaY(){
    QModelIndexList posizione1=listaElementi1->selectionModel()->selectedIndexes();
    if(!posizione1.isEmpty()){
        QString text = QInputDialog::getText(this,tr("Inserisci tag"),tr("Inserisci tag"));
        modello->inserisciElemento(modello->numeroElementi(),modello->ritornaElemento(posizione1[0].row())->simmetricoY(text));
    }

}

void MainKalk::traslazione(){
    QModelIndexList posizione1=listaElementi1->selectionModel()->selectedIndexes();
    if(!posizione1.isEmpty()){
        QString text = QInputDialog::getText(this,tr("Inserisci tag"),tr("Inserisci tag"));
        modello->inserisciElemento(modello->numeroElementi(),modello->ritornaElemento(posizione1[0].row())->simmetricoY(text));
    }

}
