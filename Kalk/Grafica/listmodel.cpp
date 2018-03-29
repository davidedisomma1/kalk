#include "listmodel.h"


listModel::listModel(QObject *parent): QAbstractListModel(parent){}

int listModel::rowCount(const QModelIndex & /* parent */) const
{
    return listaPunti.length();
}

QVariant listModel::data(const QModelIndex &index, int role) const{
   /* if (!index.isValid())
            return QVariant();
    if (index.row() >= listaPunti.size() || index.row() < 0)
            return QVariant(); */
    if (role == Qt::DisplayRole) {
        QVariant v=QVariant::fromValue(*(listaPunti.at(index.row())))  ;
        return v;
    }
 //   return QVariant();
}
