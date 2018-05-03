#include "inputpunto.h"


inputPunto::inputPunto(const QString& titolo, QWidget* parent): QDialog(parent){
    tagLabel=new QLabel("Tag");
    xLabel=new QLabel("X");
    yLabel=new QLabel("Y");

    inputTag=new QLineEdit;
    inputX=new QDoubleSpinBox;
    inputX->setRange(std::numeric_limits<double>::lowest(),std::numeric_limits<double>::max());
    inputX->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Minimum);
    inputY=new QDoubleSpinBox;
    inputY->setRange(std::numeric_limits<double>::lowest(),std::numeric_limits<double>::max());
    inputY->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Minimum);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    QObject::connect(buttonBox, SIGNAL(accepted()), this, SLOT(verify()));
    QObject::connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QFormLayout *mainLayout = new QFormLayout;
    mainLayout->addRow(tagLabel, inputTag);
    mainLayout->addRow(xLabel, inputX);
    mainLayout->addRow(yLabel, inputY);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);
    setWindowTitle(titolo);
}

QString inputPunto::getInputTag(){return inputTag->text();}
qreal inputPunto::getInputX(){return inputX->value();}
qreal inputPunto::getInputY(){return inputY->value();}

void inputPunto::verify(){
    accept();
    return;
}

