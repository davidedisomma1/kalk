#include "mainkalk.h"

MainKalk::MainKalk(QWidget *parent) : QWidget(parent){
        QWidget* window=new QMainWindow;
        window->resize(320, 240);
        QPushButton* creaPunto=new QPushButton("Crea punto",this);
        QObject::connect(creaPunto,SIGNAL(released()),this,SLOT(crea()));
        window->setWindowTitle(
            QApplication::translate("toplevel", "Top-level widget"));
}

void MainKalk::crea(){
    Punto hey;
    QString testo=hey.Punto::getTag();
    QLabel* verifica=new QLabel(testo,this);

}
