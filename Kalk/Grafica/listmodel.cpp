#include "listmodel.h"

listModel::listModel(QObject *parent): QAbstractListModel(parent){}

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

int listModel::numeroPunti()const{
    return listaElementi.length();
}

void listModel::inserisciPunto(int position,const Punto& p){
    insertRows(position,1);
    listaElementi.replace(position,const_cast<Punto*>(&p));
}
