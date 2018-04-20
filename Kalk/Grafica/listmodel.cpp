#include "listmodel.h"

listModel::listModel(QObject *parent): QAbstractListModel(parent){}

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



bool listModel::removeRows(int position, int rows, const QModelIndex &parent){
    beginRemoveRows(QModelIndex(), position, position+rows-1);

    for (int row = 0; row < rows; ++row) {
        Punto* p=listaPunti.takeAt(position);
        delete p;
    }

    endRemoveRows();
    return true;
}

QVariant listModel::data(const QModelIndex &index, int role) const{
    if (!index.isValid())
        return QVariant();
    if (index.row() >= listaPunti.size() || index.row() < 0)
        return QVariant();
    if (role == Qt::DisplayRole) {
        QString stringaOut;
        stringaOut.push_back((listaPunti.at(index.row()))->getTag());
        stringaOut.push_back("(");
        stringaOut.push_back(QString::number((listaPunti.at(index.row()))->x()));
        stringaOut.push_back(",");
        stringaOut.push_back(QString::number((listaPunti.at(index.row()))->y()));
        stringaOut.push_back(")");
        return  stringaOut;
    }
    return QVariant();
}

int listModel::numeroPunti()const{
    return listaPunti.length();
}

void listModel::inserisciPunto(int position,const Punto& p){
    insertRows(position,1);
    listaPunti.replace(position,const_cast<Punto*>(&p));
}
