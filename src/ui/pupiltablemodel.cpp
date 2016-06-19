#include "pupiltablemodel.h"
#include <QDebug>

PupilTableModel::PupilTableModel(QList<Pupil> pupilList)
{
    this->pupilList = pupilList;
}

void PupilTableModel::setPupilList(QList<Pupil> pupilList)
{
    qDebug() << "Reset table model with " << pupilList.length() << " entries.";
    this->beginResetModel();
    this->pupilList = pupilList;
    this->endResetModel();
    this->headerDataChanged(Qt::Vertical, 0, 1);
}

QVariant PupilTableModel::data(const QModelIndex &index, int role) const
{
    switch (index.column()) {
    case 0:
        switch(role) {
        case Qt::DisplayRole: return pupilList.at(index.row()).getForename();
        default: return QVariant();
        }

    case 1:
        switch(role) {
        case Qt::DisplayRole: return pupilList.at(index.row()).getLastname();
        default: return QVariant();
        }
    default:
        switch(role) {
        case Qt::DisplayRole: return "";
        default: QVariant();
        }
    }
}

QVariant PupilTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch (orientation) {
    case Qt::Horizontal:
        switch (role) {
        case Qt::DisplayRole:
            switch (section){
            case 0: return tr("Vorname");
            case 1: return tr("Nachname");
            default: return QVariant();
            }

        default: return QVariant();
        }
    case Qt::Vertical:
        switch (role) {
        case Qt::DisplayRole: return QVariant(section + 1);
        default: return QVariant();
        }
    default: return QVariant();
    }
/*
    switch (section) {
    case 0: return tr("Vorname");
    case 1: return tr("Nachname");
    default: return tr("");
    }*/
}

void PupilTableModel::addPupil(Pupil pupil)
{

    //beginInsertRows(createIndex(0, 0), pupilList.length() - 1, pupilList.length());
    beginResetModel();
    pupilList.append(pupil);
    endResetModel();
}
