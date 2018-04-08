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

public slots:
    void crea();

signals:
    void creato();
};

#endif // MAINKALK_H
