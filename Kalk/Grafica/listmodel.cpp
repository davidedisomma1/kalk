#include "listmodel.h"



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
            return listaPunti.at(index.row());
    }
 //   return QVariant();
}
