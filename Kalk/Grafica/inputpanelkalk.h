#ifndef INPUTPANELKALK_H
#define INPUTPANELKALK_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QDialogButtonBox>
#include <QDialog>
#include <QFormLayout>

class inputPanelKalk: public QDialog{
    Q_OBJECT
public:
    inputPanelKalk(const QString&, QWidget*);

public slots:
    void verify();

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

#endif // INPUTPANELKALK_H
