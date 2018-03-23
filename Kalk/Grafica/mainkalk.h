#ifndef MAINKALK_H
#define MAINKALK_H

#include <QWidget>
#include <QString>
#include "../Logica/punto.h"
#include <QMainWindow>
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QInputDialog>

class MainKalk : public QWidget
{
    Q_OBJECT
public:
    explicit MainKalk(QWidget *parent = 0);

public slots:
    void crea();

signals:
    void creato(Punto a);
};

#endif // MAINKALK_H
