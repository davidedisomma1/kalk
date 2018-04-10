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
    QListView* listaPunti;

    QPushButton* creaPunto;
    QPushButton* eliminaPunto;

    QGridLayout* layoutGriglia;
    listModel* modello;

public slots:
    void crea();
    void elimina();

signals:
    void creato();
};

#endif // MAINKALK_H
