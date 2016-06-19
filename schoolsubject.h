#ifndef SCHOOLSUBJECT_H
#define SCHOOLSUBJECT_H

#include <QUuid>
#include <QString>

class SchoolSubject
{
private:
    QUuid key;
    QString name;

public:
    SchoolSubject(): key(QUuid()), name(QString()) {}
    SchoolSubject(QUuid key, QString name);

    static QList<SchoolSubject> all();
    static SchoolSubject forKey(QUuid key);

    QString getName() const { return name; }
    QUuid getKey() const { return key; }
};

#endif // SCHOOLSUBJECT_H
