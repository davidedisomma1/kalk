#include "listmodel.h"


listModel::listModel(QObject *parent): QAbstractListModel(parent){
    listaPunti.push_back(new Punto("a",1,1));
}

int listModel::rowCount(const QModelIndex & parent = QModelIndex() ) const
{
    return listaPunti.length();
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
