#ifndef PUPIL_H
#define PUPIL_H

#include <QObject>
#include <QUuid>
#include "schoolclass.h"

class Pupil
{
    QUuid key;
    QString forename;
    QString lastname;
    QUuid classKey;

public:
    Pupil(QString forename, QString lastname,
          QUuid schoolKey);
    Pupil(QUuid key,
          QString forename, QString lastname,
          QUuid schoolKey);

    inline QString getForename() const { return forename; }
    inline QString getLastname() const { return lastname; }

    void save();

    static QList<Pupil> fromClass(SchoolClass schoolClass);

signals:

public slots:
};

#endif // PUPIL_H
