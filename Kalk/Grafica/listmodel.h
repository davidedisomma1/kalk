#ifndef LISTMODEL_H
#define LISTMODEL_H

#include "Logica/punto.h"
#include <QAbstractListModel>
#include <QList>

class listModel : public QAbstractListModel{
    Q_OBJECT
public:
    listModel(QObject *parent = 0);

    int rowCount(const QModelIndex &) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &parent= QModelIndex());

    void inserisciPunto(int,const Punto&);
    int numeroPunti()const;
private:
    QList<Punto*> listaPunti;
};

#endif // LISTMODEL_H
