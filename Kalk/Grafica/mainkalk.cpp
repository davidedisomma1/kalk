#include "mainkalk.h"
#include "inputpanelkalk.h"
#include "listwidg.h"

MainKalk::MainKalk(QWidget *parent) : QWidget(parent){
        QWidget* window=new QMainWindow;
        QListWidget* listaPunti=new QListWidget(this);
        QPushButton* creaPunto=new QPushButton("Crea punto",this);
        QGridLayout* layoutGriglia=new QGridLayout(this);
        listModel* modello=new listModel();

        window->resize(320, 240);
        layoutGriglia->addWidget(listaPunti);
        layoutGriglia->addWidget(creaPunto);
        QObject::connect(creaPunto,SIGNAL(released()),this,SLOT(crea()));
}

void MainKalk::crea(){
    inputPanelKalk *prova=new inputPanelKalk("Crea Punto",this);
    if(prova->exec()==QDialog::Accepted){
        Punto *nuovoPunto=new Punto(prova->getInputTag(),prova->getInputX(),prova->getInputY());
        QObject::connect(this,SIGNAL(creato()),this,SLOT(aggWidg()));
    }
}

void MainKalk::aggWidg(){}
