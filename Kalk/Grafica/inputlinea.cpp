#include "inputlinea.h"

inputLinea::inputLinea(const QString& titolo, QWidget* parent): QDialog(parent){
    inizioLabel=new QLabel("Tag punto inizio");
    xLabela=new QLabel("X inizio");
    yLabela=new QLabel("Y inizio");
    fineLabel=new QLabel("Tag punto fine");
    xLabelb=new QLabel("X fine");
    yLabelb=new QLabel("Y fine");

    inputTagInizio=new QLineEdit;
    inputXa=new QDoubleSpinBox;
    inputXa->setRange(std::numeric_limits<double>::lowest(),std::numeric_limits<double>::max());
    inputXa->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Minimum);
    inputYa=new QDoubleSpinBox;
    inputYa->setRange(std::numeric_limits<double>::lowest(),std::numeric_limits<double>::max());
    inputYa->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Minimum);

    inputTagFine=new QLineEdit;
    inputXb=new QDoubleSpinBox;
    inputXb->setRange(std::numeric_limits<double>::lowest(),std::numeric_limits<double>::max());
    inputXb->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Minimum);
    inputYb=new QDoubleSpinBox;
    inputYb->setRange(std::numeric_limits<double>::lowest(),std::numeric_limits<double>::max());
    inputYb->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Minimum);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    QObject::connect(buttonBox, SIGNAL(accepted()), this, SLOT(verify()));
    QObject::connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QFormLayout *mainLayout = new QFormLayout;
    mainLayout->addRow(inizioLabel, inputTagInizio);
    mainLayout->addRow(xLabela, inputXa);
    mainLayout->addRow(yLabela, inputYa);
    mainLayout->addRow(fineLabel, inputTagFine);
    mainLayout->addRow(xLabelb, inputXb);
    mainLayout->addRow(yLabelb, inputYb);
    mainLayout->addWidget(buttonBox);

    QWidget::setLayout(mainLayout);
    QWidget::setWindowTitle(titolo);

}

QString inputLinea::getInputTagInizio(){return inputTagInizio->text();}
QString inputLinea::getInputTagFine(){return inputTagFine->text();}
qreal inputLinea::getInputXa(){return inputXa->value();}
qreal inputLinea::getInputYa(){return inputYa->value();}
qreal inputLinea::getInputXb(){return inputXb->value();}
qreal inputLinea::getInputYb(){return inputYb->value();}


void inputLinea::verify(){
    accept();
    return;
}

