#include "dialog.h"
#include "inputpunto.h"

Dialog::Dialog():modello(new listModel()){
    opGenerali(); //Creo la vista delle operazioni unarie
    opBinarie(); //Creo la vista delle operazioni binarie
    QVBoxLayout *mainLayout=new QVBoxLayout;
    mainLayout->addWidget(elementiGenerali);
    mainLayout->addWidget(operazBinarie);
    setLayout(mainLayout);
    setWindowTitle(tr("Kalk"));
}

void Dialog::opGenerali(){
    elementiGenerali=new QGroupBox(tr("Operazioni unarie"));
    QGridLayout *layoutGen=new QGridLayout;
//  AGGIUNGO TUTTI I BOTTONI UNARI APPLICABILI A TUTTE LE CLASSI
    listaElementi=new QListView(this);
    listaElementi->setModel(modello);

    buttonCreaPunto=new QPushButton("Crea punto",this);
    buttonCreaLinea=new QPushButton("Crea linea",this);
    buttonElimina=new QPushButton("Elimina elemento",this);
    buttonModifyTag=new QPushButton("Modifica tag",this);
    buttonSimmetricoX=new QPushButton("Simmetrico X",this);
    buttonSimmetricoY=new QPushButton("Simmetrico Y",this);
    buttonSimmetricoO=new QPushButton("Simmetrico Origine",this);
    buttonTraslazione=new QPushButton("Traslazione",this);
    buttonLunghezza=new QPushButton("Lunghezza elemento",this);

    layoutGen->addWidget(listaElementi,0,0,5,1);
    layoutGen->addWidget(buttonCreaPunto,0,1,1,1);
    layoutGen->addWidget(buttonCreaLinea,1,1,1,1);
    layoutGen->addWidget(buttonElimina,2,1,1,1);
    layoutGen->addWidget(buttonModifyTag,3,1,1,1);
    layoutGen->addWidget(buttonSimmetricoX,0,2,1,1);
    layoutGen->addWidget(buttonSimmetricoY,1,2,1,1);
    layoutGen->addWidget(buttonSimmetricoO,2,2,1,1);
    layoutGen->addWidget(buttonTraslazione,3,2,1,1);
    layoutGen->addWidget(buttonLunghezza,4,1,1,2);

    elementiGenerali->setLayout(layoutGen);

    QObject::connect(buttonCreaPunto,SIGNAL(released()),this,SLOT(creaPunto()));
    QObject::connect(buttonCreaLinea,SIGNAL(released()),this,SLOT(creaLinea()));
    QObject::connect(buttonElimina,SIGNAL(released()),this,SLOT(elimina()));
    QObject::connect(buttonModifyTag,SIGNAL(released()),this,SLOT(cambiaTag()));
    QObject::connect(buttonSimmetricoO,SIGNAL(released()),this,SLOT(simmetriaO()));
    QObject::connect(buttonSimmetricoX,SIGNAL(released()),this,SLOT(simmetriaX()));
    QObject::connect(buttonSimmetricoY,SIGNAL(released()),this,SLOT(simmetriaY()));
    QObject::connect(buttonTraslazione,SIGNAL(released()),this,SLOT(traslazione()));
    QObject::connect(buttonLunghezza,SIGNAL(released()),this,SLOT(lunghezza()));
//CREO E AGGIUNGO LA VISTA DELLE OPERAZIONI UNARIE SPECIFICHE PER PUNTI
    opPuntiUnarie();
    layoutGen->addWidget(operazPuntiUn,0,3,2,1);
//CREO E AGGIUNGO LA VISTA DELLE OPERAZIONI UNARIE SPECIFICHE PER LINEE
    opLineeUnarie();
    layoutGen->addWidget(operazLineeUn,2,3,2,1);
//CREO E AGGIUNGO LA VISTA DELLE OPERAZIONI UNARIE SPECIFICHE PER SPEZZATE
    opSpezzateUnarie();
    layoutGen->addWidget(operazSpezzateUn,0,4,2,1);
}

void Dialog::opBinarie(){
    operazBinarie=new QGroupBox(tr("Operazioni binarie"));
    QGridLayout *layoutOp=new QGridLayout;
//  AGGIUNGO TUTTI I BOTTONI BINARI APPLICABILI A TUTTE LE CLASSI
    selezioneElementoUno=new QComboBox();
    selezioneElementoDue=new QComboBox();
    labelSelezione=new QLabel(tr("Seleziona i due elementi"));
    labelSelezione->setAlignment(Qt::AlignLeft);


    selezioneElementoUno->setModel(modello);
    selezioneElementoDue->setModel(modello);

    buttonAddizione=new QPushButton("Somma",this);
    layoutOp->addWidget(labelSelezione,0,0);
    layoutOp->addWidget(selezioneElementoUno,1,0);
    layoutOp->addWidget(selezioneElementoDue,1,1);
    layoutOp->addWidget(buttonAddizione,3,0,1,2);

    QObject::connect(buttonAddizione,SIGNAL(released()),this,SLOT(addizione()));
//CREO E AGGIUNGO LA VISTA DELLE OPERAZIONI BINARIE SPECIFICHE PER PUNTI
    opPuntiBinarie();
    layoutOp->addWidget(operazPuntiBin);
//CREO E AGGIUNGO LA VISTA DELLE OPERAZIONI BINARIE SPECIFICHE PER LINEE
    opLineeBinarie();
    layoutOp->addWidget(operazLineeBin);
    operazBinarie->setLayout(layoutOp);
}

void Dialog::opPuntiUnarie(){
    operazPuntiUn=new QGroupBox(tr("Operazioni per punti"));
    QVBoxLayout *layoutPunti=new QVBoxLayout;

    buttonDistanzaO=new QPushButton("Distanza da origine",this);
    layoutPunti->addWidget(buttonDistanzaO);
    QObject::connect(buttonDistanzaO,SIGNAL(released()),this,SLOT(distanzaO()));

    operazPuntiUn->setLayout(layoutPunti);


}

void Dialog::opPuntiBinarie(){
    operazPuntiBin=new QGroupBox(tr("Operazioni per punti"));
    QHBoxLayout *layoutP=new QHBoxLayout;

    buttonDistanzaP=new QPushButton("Distanza tra punti",this);
    layoutP->addWidget(buttonDistanzaP);
    QObject::connect(buttonDistanzaP,SIGNAL(released()),this,SLOT(distanzaP()));

    operazPuntiBin->setLayout(layoutP);
}

void Dialog::opLineeUnarie(){
    operazLineeUn=new QGroupBox(tr("Operazioni per linee"));
    QVBoxLayout *layoutL=new QVBoxLayout;

    buttonPuntoMedio=new QPushButton("Punto medio",this);
    layoutL->addWidget(buttonPuntoMedio);

    QObject::connect(buttonPuntoMedio,SIGNAL(released()),this,SLOT(puntoMedio()));

    operazLineeUn->setLayout(layoutL);
}

void Dialog::opLineeBinarie(){
    operazLineeBin=new QGroupBox(tr("Operazioni per linee"));
    QVBoxLayout *layoutL=new QVBoxLayout;

    buttonSommaVettoriale=new QPushButton("Somma vettoriale",this);
    layoutL->addWidget(buttonSommaVettoriale);
    QObject::connect(buttonSommaVettoriale,SIGNAL(released()),this,SLOT(sommaVettoriale()));

    operazLineeBin->setLayout(layoutL);
}

void Dialog::opSpezzateUnarie(){
    operazSpezzateUn=new QGroupBox(tr("Operazioni per spezzate"));
    QVBoxLayout *layoutS=new QVBoxLayout;

    buttonConnetti=new QPushButton("Chiudi spezzata",this);
    layoutS ->addWidget(buttonConnetti);

    QObject::connect(buttonConnetti,SIGNAL(released()),this,SLOT(connettiSpezzata()));

    operazSpezzateUn->setLayout(layoutS);
}
void Dialog::creaPunto(){
    inputPunto *inputNuovoPunto=new inputPunto("Crea Punto",this);
    if(inputNuovoPunto->exec()==QDialog::Accepted && !modello->trovaDuplicato(inputNuovoPunto->getInputTag())){
        Punto *nuovoPunto=new Punto(inputNuovoPunto->getInputTag(),inputNuovoPunto->getInputX(),inputNuovoPunto->getInputY());
        modello->inserisciElemento(modello->rowCount(QModelIndex()),nuovoPunto);
    }
    delete inputNuovoPunto;
}

void Dialog::creaLinea(){
    Linea* nuovaLinea=new Linea();
    inputPunto *inputPuntoInizio=new inputPunto("Crea Punto Inizio",this);
    if(inputPuntoInizio->exec()==QDialog::Accepted){
        Punto *nuovoPunto=new Punto(inputPuntoInizio->getInputTag(),inputPuntoInizio->getInputX(),inputPuntoInizio->getInputY());
        if(!modello->trovaDuplicato(inputPuntoInizio->getInputTag())) modello->inserisciElemento(modello->rowCount(QModelIndex()),nuovoPunto);
        else return;
        nuovaLinea->setInizio(*nuovoPunto);
        nuovaLinea->setTag(nuovoPunto->getTag());
    }
    delete inputPuntoInizio;
    inputPunto *inputPuntoFine=new inputPunto("Crea Punto Fine",this);
    if(inputPuntoFine->exec()==QDialog::Accepted){
        Punto *nuovoPunto=new Punto(inputPuntoFine->getInputTag(),inputPuntoFine->getInputX(),inputPuntoFine->getInputY());
        if(!modello->trovaDuplicato(inputPuntoFine->getInputTag())) modello->inserisciElemento(modello->rowCount(QModelIndex()),nuovoPunto);
        else return;
        nuovaLinea->setFine(*nuovoPunto);
        nuovaLinea->setTag(nuovaLinea->getTag()+nuovoPunto->getTag());
    }
    delete inputPuntoFine;
    if(!modello->trovaDuplicato(nuovaLinea->getTag())) modello->inserisciElemento(modello->rowCount(QModelIndex()),nuovaLinea);
}

void Dialog::elimina(){
    QModelIndexList posizione1=listaElementi->selectionModel()->selectedIndexes();
    if(!posizione1.isEmpty())
    modello->removeRows(posizione1[0].row(),1);
}

void Dialog::cambiaTag(){
    QModelIndexList posizione1=listaElementi->selectionModel()->selectedIndexes();
    if(!posizione1.isEmpty()){
        QString text = QInputDialog::getText(this,tr("Inserisci tag"),tr("Inserisci tag"));
        if(!modello->trovaDuplicato(text)){
            modello->ritornaElemento(posizione1[0].row())->setTag(text);
            modello->aggiorna(posizione1[0]);
        }
    }
}

void Dialog::simmetriaO(){
    QModelIndexList posizione1=listaElementi->selectionModel()->selectedIndexes();
    if(!posizione1.isEmpty()){
        QString text = QInputDialog::getText(this,tr("Inserisci tag"),tr("Inserisci tag"));
        if(!modello->trovaDuplicato(text))
        modello->inserisciElemento(modello->rowCount(QModelIndex()),modello->ritornaElemento(posizione1[0].row())->simmetricoO(text));
    }
}

void Dialog::simmetriaX(){
    QModelIndexList posizione1=listaElementi->selectionModel()->selectedIndexes();
    if(!posizione1.isEmpty()){
        QString text = QInputDialog::getText(this,tr("Inserisci tag"),tr("Inserisci tag"));
        if(!modello->trovaDuplicato(text))
        modello->inserisciElemento(modello->rowCount(QModelIndex()),modello->ritornaElemento(posizione1[0].row())->simmetricoX(text));
    }
}

void Dialog::simmetriaY(){
    QModelIndexList posizione1=listaElementi->selectionModel()->selectedIndexes();
    if(!posizione1.isEmpty()){
        QString text = QInputDialog::getText(this,tr("Inserisci tag"),tr("Inserisci tag"));
        if(!modello->trovaDuplicato(text))
        modello->inserisciElemento(modello->rowCount(QModelIndex()),modello->ritornaElemento(posizione1[0].row())->simmetricoY(text));
    }
}

void Dialog::traslazione(){
    QModelIndexList posizione1=listaElementi->selectionModel()->selectedIndexes();
    if(!posizione1.isEmpty()){
        double nuovoX = QInputDialog::getDouble(this,tr("Inserisci x"),tr("Inserisci x"));
        double nuovoY = QInputDialog::getDouble(this,tr("Inserisci y"),tr("Inserisci y"));
        modello->ritornaElemento(posizione1[0].row())->traslazione(nuovoX,nuovoY);
        modello->traslaComponenti(modello->ritornaElemento(posizione1[0].row()),modello->ritornaElemento(posizione1[0].row())->getTag(),nuovoX,nuovoY);
        modello->aggiorna(posizione1[0]);
    }
}

void Dialog::lunghezza(){
    QModelIndexList posizione1=listaElementi->selectionModel()->selectedIndexes();
    QMessageBox msgBox;
    if(dynamic_cast<Linea*>(modello->ritornaElemento(posizione1[0].row())))
        msgBox.setText(QString::number(static_cast<Linea*>(modello->ritornaElemento(posizione1[0].row()))->lunghezza()));
    else
        msgBox.setText("0");
    msgBox.exec();
}

void Dialog::addizione(){
    int posizione1=selezioneElementoUno->currentIndex();
    int posizione2=selezioneElementoDue->currentIndex();
    modello->inserisciElemento(modello->rowCount(QModelIndex()), *(modello->ritornaElemento(posizione1))+ *(modello->ritornaElemento(posizione2)));
}

void Dialog::distanzaP(){
    int posizione1=selezioneElementoUno->currentIndex();
    int posizione2=selezioneElementoDue->currentIndex();
    if(dynamic_cast<Punto*>(modello->ritornaElemento(posizione1)) && dynamic_cast<Punto*>(modello->ritornaElemento(posizione2))){
        QMessageBox msgBox;
        msgBox.setText(QString::number(static_cast<Punto*>(modello->ritornaElemento(posizione1))
                       ->distanzaP(*static_cast<Punto*>(modello->ritornaElemento(posizione2)))));
        msgBox.exec();
    }
}

void Dialog::distanzaO(){
    QModelIndexList posizione1=listaElementi->selectionModel()->selectedIndexes();
    if(dynamic_cast<Punto*>(modello->ritornaElemento(posizione1[0].row()))){
        QMessageBox msgBox;
        msgBox.setText(QString::number(static_cast<Punto*>(modello->ritornaElemento(posizione1[0].row()))->distanzaO()));
        msgBox.exec();
    }
}

void Dialog::puntoMedio(){
     QModelIndexList posizione1=listaElementi->selectionModel()->selectedIndexes();
     if(typeid(*(modello->ritornaElemento(posizione1[0].row())))==typeid(Linea)){
     QString text = QInputDialog::getText(this,tr("Inserisci tag"),tr("Inserisci tag"));
     if(!modello->trovaDuplicato(text))
     modello->inserisciElemento(modello->rowCount(QModelIndex()),static_cast<Linea*>(modello->ritornaElemento(posizione1[0].row()))->puntoMedio(text));
     }
}


void Dialog::sommaVettoriale(){
    int posizione1=selezioneElementoUno->currentIndex();
    int posizione2=selezioneElementoDue->currentIndex();
    if(typeid(Linea)==typeid(*(modello->ritornaElemento(posizione1))) &&
           typeid(Linea)==typeid(*(modello->ritornaElemento(posizione2)))){
    modello->inserisciElemento(modello->rowCount(QModelIndex()),static_cast<Linea*>(modello->ritornaElemento(posizione1))
           ->sommaVettoriale((*static_cast<Linea*>((modello->ritornaElemento(posizione2))))));
    }
}

void Dialog::connettiSpezzata(){
    QModelIndexList posizione1=listaElementi->selectionModel()->selectedIndexes();
    if(typeid(*(modello->ritornaElemento(posizione1[0].row())))==typeid(Spezzata)){
        QString text = QInputDialog::getText(this,tr("Inserisci tag"),tr("Inserisci tag"));
        if(!modello->trovaDuplicato(text))
        modello->inserisciElemento(modello->rowCount(QModelIndex()),static_cast<Spezzata*>(modello->ritornaElemento(posizione1[0].row()))->chiudiSpezzata(text));
    }
}