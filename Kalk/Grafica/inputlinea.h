#ifndef INPUTLINEA_H
#define INPUTLINEA_H
#include "inputpunto.h"

class inputLinea:public QDialog{
    Q_OBJECT
public:
    inputLinea(const QString&, QWidget*);

public slots:
    void verify();

signals:
    void creato(const Linea*);

public:
    QString getInputTagInizio();
    QString getInputTagFine();
    qreal getInputXa();
    qreal getInputYa();
    qreal getInputXb();
    qreal getInputYb();
private:
    QLabel *inizioLabel;
    QLabel *fineLabel;
    QLabel *xLabela;
    QLabel *yLabela;
    QLabel *xLabelb;
    QLabel *yLabelb;

    QLineEdit *inputTagInizio;
    QLineEdit *inputTagFine;
    QDoubleSpinBox *inputXa;
    QDoubleSpinBox *inputYa;
    QDoubleSpinBox *inputXb;
    QDoubleSpinBox *inputYb;

    QDialogButtonBox *buttonBox;
};

#endif // INPUTPUNTO_H
