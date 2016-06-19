#ifndef SCHOOL_H
#define SCHOOL_H

#include <QObject>
#include <QUuid>
#include <QList>

class School
{
private:
    QUuid key;
    QString schoolName;

public:
    School(const QString name);
    explicit School(QUuid key, QString name);

    static School fromDatabase(QUuid key);
    static QList<School> all();

    void save();
    void remove();

    inline QString getSchoolName() { return schoolName; }
    inline QUuid getKey() { return key; }

signals:

public slots:
};

#endif // SCHOOL_H
