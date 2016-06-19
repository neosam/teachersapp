#ifndef LESSONSCHEDULEMODEL_H
#define LESSONSCHEDULEMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QMap>
#include "lessonschedulemodel.h"
#include "schoolsubject.h"

class LessonScheduleModel : public QAbstractTableModel
{
private:
    QMap<QString, SchoolSubject> dataMap;


public:
    LessonScheduleModel();

    QString indexToKey(const QModelIndex &index) const;
    virtual int rowCount(const QModelIndex &) const { return 6; }
    virtual int columnCount(const QModelIndex &) const { return 5; }
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    void insert(const QModelIndex &index, SchoolSubject subject);
};

#endif // LESSONSCHEDULEMODEL_H
