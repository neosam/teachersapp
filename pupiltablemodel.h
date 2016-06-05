#ifndef PUPILTABLEMODEL_H
#define PUPILTABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "pupil.h"

class PupilTableModel : public QAbstractTableModel
{
private:
    QList<Pupil> pupilList;

public:
    PupilTableModel(QList<Pupil> pupilList);

    virtual int rowCount(const QModelIndex &) const { return pupilList.length(); }
    virtual int columnCount(const QModelIndex &) const { return 2; }
    virtual QModelIndex index(int row, int column, const QModelIndex &/*parent*/) const { return createIndex(row, column); }
    virtual QModelIndex parent(const QModelIndex &/*index*/) const { return createIndex(0, 0); }
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    void setPupilList(QList<Pupil> pupilList);
    void addPupil(Pupil pupil);
};

#endif // PUPILTABLEMODEL_H
