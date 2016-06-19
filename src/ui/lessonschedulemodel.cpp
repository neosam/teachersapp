#include "lessonschedulemodel.h"

#include "addscheduledialog.h"

LessonScheduleModel::LessonScheduleModel()
{

}

QString LessonScheduleModel::indexToKey(const QModelIndex &index) const {
    return QVariant(index.column()).toString() + "-" +
            QVariant(index.row()).toString();
}

QVariant LessonScheduleModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        QString key = indexToKey(index);
        if (dataMap.contains(key)) {
            SchoolSubject subject = dataMap.value(key);
            return subject.getName();
        } else {
            return "";
        }
    } else {
        return QVariant();
    }
}

QVariant LessonScheduleModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal) {
        switch (role) {
        case Qt::DisplayRole:
            switch (section) {
            case 0: return tr("Montag");
            case 1: return tr("Dienstag");
            case 2: return tr("Mittwoch");
            case 3: return tr("Donnerstag");
            case 4: return tr("Freitag");
            default: return tr("");
            }
        default: return QVariant();
        }

    } else {
        return section + 1;
    }
}


void LessonScheduleModel::insert(const QModelIndex &index, SchoolSubject subject) {
    QString key = indexToKey(index);
    dataMap.insert(key, subject);
}
