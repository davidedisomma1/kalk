#ifndef LISTMODEL_H
#define LISTMODEL_H

#include "Logica/punto.h"
#include <QAbstractListModel>
#include <QList>

class listModel : public QAbstractListModel{

public:
    listModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
private:
    QList<Punto*> listaPunti;
};

#endif // LISTMODEL_H