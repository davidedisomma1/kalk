#ifndef MAINKALK_H
#define MAINKALK_H

#include "../Logica/punto.h"
#include "listmodel.h"
#include <QWidget>
#include <QString>
#include <QMainWindow>
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QInputDialog>
#include <QListView>
#include <QGridLayout>

class MainKalk : public QWidget
{
    Q_OBJECT

public:
    explicit MainKalk(QWidget *parent = 0);

    QWidget* window;
    QListView* listaElementi1;
    QListView* listaElementi2;

    QPushButton* buttonCreaPunto;
    QPushButton* buttonCreaLinea;
    QPushButton* buttonElimina;
    QPushButton* buttonModifyTag;
    QPushButton* buttonSimmetricoX;
    QPushButton* buttonSimmetricoY;
    QPushButton* buttonSimmetricoO;
    QPushButton* buttonTraslazione;
    QPushButton* buttonAddizione;
    QPushButton* buttonDistanzaO;
    QPushButton* buttonDistanzaP;
    QPushButton* buttonLunghezza;
    QPushButton* buttonPuntoMedio;
    QPushButton* buttonSommaVettoriale;
    QGridLayout* layoutGriglia;
    QGridLayout* layoutButton;
    listModel* modello;

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
signals:
};

#endif // MAINKALK_H
