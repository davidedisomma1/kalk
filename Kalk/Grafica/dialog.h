#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include<QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include<QListView>
#include <QPushButton>
#include <QInputDialog>
#include "listmodel.h"
#include <QComboBox>
#include <QLabel>
#include <QMessageBox>

class Dialog:public QDialog{
    Q_OBJECT
public:
    Dialog();
private:
/*Queste funzioni creano l'interfaccia grafica pezzo per pezzo*/
    void opGenerali();
    void opBinarie();
    void opPuntiUnarie();
    void opPuntiBinarie();
    void opLineeUnarie();
    void opLineeBinarie();
    void opSpezzateUnarie();
    void opSpezzateBinarie();
  //  void opRettangoli();

/*Questi elementi creano i gruppi di operazioni*/
    QGroupBox* elementiGenerali;
    QGroupBox* operazBinarie;
    QGroupBox* operazPuntiUn;
    QGroupBox* operazPuntiBin;
    QGroupBox* operazLineeUn;
    QGroupBox* operazLineeBin;
    QGroupBox* operazSpezzateUn;
    //QGroupBox* operazSpezzateBin;
    //QGroupBox* operazRettangoliUn;
    //QGroupBox* operazRettangoliBin;

    QListView* listaElementi;

/*Selezione unaria e bottoni UNARI*/
    listModel* modello;
    //Bottoni generici
    QPushButton* buttonCreaPunto;
    QPushButton* buttonCreaLinea;
    QPushButton* buttonElimina;
    QPushButton* buttonModifyTag;
    QPushButton* buttonSimmetricoX;
    QPushButton* buttonSimmetricoY;
    QPushButton* buttonSimmetricoO;
    QPushButton* buttonTraslazione;
    QPushButton* buttonLunghezza;
    //Bottoni per punti
    QPushButton* buttonDistanzaO;
    //Bottoni per linee
    QPushButton* buttonPuntoMedio;
    //Bottoni per spezzate
    QPushButton* buttonConnetti;

/*Selezione di due elementi e bottoni BINARI*/
    QComboBox* selezioneElementoUno;
    QComboBox* selezioneElementoDue;
    QLabel* labelSelezione;
    //Bottoni generici
    QPushButton* buttonAddizione;
    //Bottni per punti
    QPushButton* buttonDistanzaP;
    //Bottoni per linee
    QPushButton* buttonSommaVettoriale;

public slots:
    void creaPunto();
    void creaLinea();
    void elimina();
    void cambiaTag();
    void simmetriaX();
    void simmetriaY();
    void simmetriaO();
    void traslazione();
    void addizione();
    void distanzaO();
    void distanzaP();
    void lunghezza();
    void puntoMedio();
    void sommaVettoriale();
    void connettiSpezzata();
signals:
};

#endif // DIALOG_H
