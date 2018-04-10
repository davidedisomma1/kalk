#include "mainkalk.h"
#include "inputpanelkalk.h"


MainKalk::MainKalk(QWidget *parent) : QWidget(parent){
        window=new QMainWindow;
        listaPunti=new QListView(this);
        creaPunto=new QPushButton("Crea punto",this);
        eliminaPunto=new QPushButton("Elimina punto",this);
        layoutGriglia=new QGridLayout(this);
        modello=new listModel(listaPunti);

        listaPunti->setModel(modello);

        window->resize(320, 240);
        layoutGriglia->addWidget(listaPunti);
        layoutGriglia->addWidget(creaPunto);
        layoutGriglia->addWidget(eliminaPunto);
        QObject::connect(creaPunto,SIGNAL(released()),this,SLOT(crea()));
        QObject::connect(eliminaPunto,SIGNAL(released()),this,SLOT(elimina()));
}

void MainKalk::crea(){
    inputPanelKalk *prova=new inputPanelKalk("Crea Punto",this);
    if(prova->exec()==QDialog::Accepted){
        Punto *nuovoPunto=new Punto(prova->getInputTag(),prova->getInputX(),prova->getInputY());
        modello->inserisciPunto(modello->numeroPunti(),*nuovoPunto);
    }
}

void MainKalk::elimina(){
    QModelIndexList posizione=listaPunti->selectionModel()->selectedIndexes();
    int intero=posizione[0].row();
    modello->removeRows(intero,1);

}




