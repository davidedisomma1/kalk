#include "listmodel.h"
#include <typeinfo>

listModel::listModel(QObject *parent): QAbstractListModel(parent){
    listaElementi.push_back(&Punto::origine);
}

int listModel::rowCount(const QModelIndex & parent = QModelIndex() ) const
{
    return listaElementi.length();
}

bool listModel::insertRows(int position, int rows, const QModelIndex &parent){
    beginInsertRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row) {
        listaElementi.insert(position, 0);
    }

    endInsertRows();
    return true;
}


bool listModel::removeRows(int position, int rows, const QModelIndex &parent){
    beginRemoveRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row) {
        delete listaElementi.takeAt(position);
    }

    endRemoveRows();
    return true;
}

QVariant listModel::data(const QModelIndex &index, int role) const{
    if (!index.isValid())
        return QVariant();
    if (index.row() >= listaElementi.size() || index.row() < 0)
        return QVariant();
    if (role == Qt::DisplayRole) {

    return (listaElementi.at(index.row()))->output();

    }
    return QVariant();
}


void listModel::inserisciElemento(int position, Tag* p){
    insertRows(position,1);
    listaElementi.replace(position,p);
}

Tag* listModel::ritornaElemento(int position)const{
    return listaElementi.at(position);
}

bool listModel::trovaDuplicato(QString s)const{
    for(auto it=listaElementi.begin();it!=listaElementi.end();++it){
        if((*it)->getTag()==s) return true;
    }
    return false;
}

void listModel::aggiorna(const QModelIndex& i){
    dataChanged(i, i);
}

void listModel::traslaComponenti(Tag* o,double nX,double nY){
    if(typeid(*o)==typeid(Linea)){
    for(auto it=listaElementi.constBegin();it!=listaElementi.constEnd();++it){
        if((*it)->getTag()==(static_cast<Linea*>(o)->getFineTag()))
            (const_cast<Tag*>(*it))->traslazione(nX,nY);
        if((*it)->getTag()==(static_cast<Linea*>(o)->getInizioTag()))
            (const_cast<Tag*>(*it))->traslazione(nX,nY);
        }
    }
    if(typeid(*o)==typeid(Spezzata)){
    for(auto it=listaElementi.constBegin();it!=listaElementi.constEnd();++it){
        QString s=(*it)->getTag();
        if(s==(static_cast<Linea*>(o)->getFineTag()))
            (const_cast<Tag*>(*it))->traslazione(nX,nY);
        if(s==(static_cast<Linea*>(o)->getInizioTag()))
            (const_cast<Tag*>(*it))->traslazione(nX,nY);
        if(static_cast<Spezzata*>(o)->trovaPunto(s)){
            (const_cast<Tag*>(*it))->traslazione(nX,nY);
            }
        }
    }
    if(typeid(*o)==typeid(Rettangolo)){
    for(auto it=listaElementi.constBegin();it!=listaElementi.constEnd();++it){
        QString s=(*it)->getTag();
        if(s==(static_cast<Linea*>(o)->getInizioTag()))
            (const_cast<Tag*>(*it))->traslazione(nX,nY);
        if(static_cast<Spezzata*>(o)->trovaPunto(s)){
            (const_cast<Tag*>(*it))->traslazione(nX,nY);
            }
        }
    }

}
