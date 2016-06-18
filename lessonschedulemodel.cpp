#include "lessonschedulemodel.h"

#include "addscheduledialog.h"

LessonScheduleModel::LessonScheduleModel()
{

}

QVariant LessonScheduleModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        return "";
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


