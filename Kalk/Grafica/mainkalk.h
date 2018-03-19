#ifndef MAINKALK_H
#define MAINKALK_H

#include <QWidget>
#include <QString>
#include "../Logica/punto.h"
#include <QMainWindow>
#include <QPushButton>
#include <QApplication>
#include <QLabel>

class MainKalk : public QWidget
{
    Q_OBJECT
public:
    explicit MainKalk(QWidget *parent = 0);

signals:

public slots:
    void crea();
};

#endif // MAINKALK_H
