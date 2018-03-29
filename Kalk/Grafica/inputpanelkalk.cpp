#include "inputpanelkalk.h"


inputPanelKalk::inputPanelKalk(const QString& titolo, QWidget* parent): QDialog(parent){
    tagLabel=new QLabel("Tag");
    xLabel=new QLabel("X");
    yLabel=new QLabel("Y");

    inputTag=new QLineEdit;
    inputX=new QDoubleSpinBox;
    inputY=new QDoubleSpinBox;

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

QString inputPanelKalk::getInputTag(){return inputTag->text();}
qreal inputPanelKalk::getInputX(){return inputX->value();}
qreal inputPanelKalk::getInputY(){return inputY->value();}

void inputPanelKalk::verify(){
    accept();
    return;
}

