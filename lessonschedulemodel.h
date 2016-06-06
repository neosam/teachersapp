#ifndef LESSONSCHEDULEMODEL_H
#define LESSONSCHEDULEMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include "lessonschedulemodel.h"

class LessonScheduleModel : public QAbstractTableModel
{
private:

public:
    LessonScheduleModel();

    virtual int rowCount(const QModelIndex &) const { return 6; }
    virtual int columnCount(const QModelIndex &) const { return 5; }
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;
};

#endif // LESSONSCHEDULEMODEL_H
