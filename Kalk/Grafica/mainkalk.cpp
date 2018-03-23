#include "mainkalk.h"
#include "inputpanelkalk.h"
MainKalk::MainKalk(QWidget *parent) : QWidget(parent){
        QWidget* window=new QMainWindow;
        window->resize(320, 240);
        QPushButton* creaPunto=new QPushButton("Crea punto",this);
        QObject::connect(creaPunto,SIGNAL(released()),this,SLOT(crea()));
        window->setWindowTitle(
            QApplication::translate("toplevel", "Top-level widget"));
}

void MainKalk::crea(){
    inputPanelKalk *prova=new inputPanelKalk("Crea Punto",this);
    if(prova->exec()==QDialog::Accepted){
        std::cout<<"Hola";
        Punto *nuovoPunto=new Punto(prova->getInputTag(),prova->getInputX(),prova->getInputY());
        std::cout<<*nuovoPunto;
    }


}
