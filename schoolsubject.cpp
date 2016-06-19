#include "schoolsubject.h"
#include <QtSql>
#include <QDebug>
#include <QUuid>

SchoolSubject::SchoolSubject(QUuid key, QString name)
{
    this->key = key;
    this->name = name;
}

QList<SchoolSubject> SchoolSubject::all() {
    QList<SchoolSubject> res;
    QSqlQuery query;
    query.prepare("SELECT school_subject_key, subject_name "
                  "FROM school_subject ");
    if (!query.exec()) {
        qDebug() << "Lesson::allLessons SQL error:  " << query.lastError().driverText();
    }
    while (query.next()) {
        SchoolSubject subject(QUuid(query.value("school_subject_key").toString()),
                              query.value("subject_name").toString());
        res.append(subject);
    }
    return res;
}

SchoolSubject SchoolSubject::forKey(QUuid key) {
    QSqlQuery query;
    query.prepare("SELECT subject_name "
                  "FROM school_subject "
                  "WHERE school_subject_key = :key");
    query.bindValue(":key", key.toString());
    if (query.exec()) {
        qDebug() << "SchoolSubject::forKey sql error:  " << query.lastError().driverText();
    }
    if (query.next()) {
        return SchoolSubject(key, query.value("subject_name").toString());
    }
    return SchoolSubject(QUuid(), QString());
}

