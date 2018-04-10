#include "listmodel.h"


listModel::listModel(QObject *parent): QAbstractListModel(parent){

}

int listModel::rowCount(const QModelIndex & parent = QModelIndex() ) const
{
    return listaPunti.length();
}

bool listModel::insertRows(int position, int rows, const QModelIndex &parent){
    beginInsertRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row) {
        listaPunti.insert(position, new Punto());
    }

    endInsertRows();
    return true;
}

int listModel::numeroPunti()const{
    return listaPunti.length();
}

void listModel::inserisciPunto(int position,const Punto& p){
    insertRows(position,1);
    listaPunti.replace(position,const_cast<Punto*>(&p));
}

bool listModel::removeRows(int position, int rows, const QModelIndex &parent){
    beginRemoveRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row) {
        listaPunti.removeAt(position);
    }

    endRemoveRows();
    return true;
}

QVariant listModel::data(const QModelIndex &index, int role) const{
   /* if (!index.isValid())
            return QVariant();
    if (index.row() >= listaPunti.size() || index.row() < 0)
            return QVariant(); */
    if (role == Qt::DisplayRole) {
        QString stringa;

        stringa.push_back((listaPunti.at(index.row()))->getTag());
      return  stringa;
       // QVariant v=QVariant::fromValue(*(listaPunti.at(index.row())))  ;
       // return v;
    }
    return QVariant();
}
