#ifndef LISTMODEL_H
#define LISTMODEL_H

#include "Logica/punto.h"
#include "Logica/linea.h"
#include "Logica/spezzata.h"
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

    void inserisciElemento(int,Tag*);
    Tag* ritornaElemento(int)const;
    bool trovaDuplicato(QString)const;
    void traslaComponenti(Tag*, double, double);
    void aggiorna(const QModelIndex&);
private:
    QList<Tag*> listaElementi;
};

#endif // LISTMODEL_H
