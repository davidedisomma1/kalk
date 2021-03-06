#ifndef INPUTPUNTO_H
#define INPUTPUNTO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QDialogButtonBox>
#include <QDialog>
#include <QFormLayout>
#include "../Logica/punto.h"
#include "../Logica/linea.h"

class inputPunto: public QDialog{
    Q_OBJECT
public:
    inputPunto(const QString&, QWidget*);

public slots:
    void verify();

signals:
    void creato(const Punto*);

public:
    QString getInputTag();
    qreal getInputX();
    qreal getInputY();

private:
    QLabel *tagLabel;
    QLabel *xLabel;
    QLabel *yLabel;

    QLineEdit *inputTag;
    QDoubleSpinBox *inputX;
    QDoubleSpinBox *inputY;

    QDialogButtonBox *buttonBox;
};

#endif // INPUTPUNTO_H
