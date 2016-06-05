#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H

#include <QUuid>
#include <QList>
#include <school.h>

class SchoolClass
{
private:
    QUuid key;
    QString label;
    QUuid schoolKey;

public:
    SchoolClass(QString label, QUuid schoolKey);
    SchoolClass(QUuid key, QString label, QUuid schoolKey);

    static QList<SchoolClass> classesInSchool(School school);

    void save();
    void remove();

    inline QString getLabel() { return label; }
    inline QUuid getKey() const { return key; }
    inline QUuid getSchoolKey() const { return schoolKey; }
};

#endif // SCHOOLCLASS_H
