#include "school.h"
#include <QtSql>
#include <QDebug>

School::School(const QString name)
{
    key = QUuid::createUuid();
    schoolName = name;
}

School::School(QUuid key, QString name)
{
    this->key = key;
    schoolName = name;
}

School School::fromDatabase(QUuid key)
{
    QSqlQuery query;
    query.prepare("SELECT school_name "
                  "FROM school "
                  "WHERE school_key = :key");
    query.bindValue(":key", key.toString());
    query.exec();
    if (query.next()) {
        return School(query.value("school_name").toString());
    }
    return School("");
}

QList<School> School::all()
{
    QList<School> res;
    QSqlQuery query;
    query.prepare("SELECT school_key, school_name "
                  "FROM school");
    if (!query.exec()) {
        qDebug() << "School::all SQL error: "
                 << query.lastError().driverText();
    }
    while(query.next()) {
        School school(QUuid(query.value("school_key").toString()),
                      query.value("school_name").toString());
        res.append(school);
    }
    return res;
}

void School::save() {
    QSqlQuery query;
    query.prepare("INSERT OR REPLACE INTO school "
                  "(school_key, school_name) "
                  "VALUES (:key, :name)");
    query.bindValue(":key", key.toString());
    query.bindValue(":name", schoolName);
    query.exec();
}

void School::remove() {
    QSqlQuery query;
    query.prepare("DELETE FROM school "
                  "WHERE school_key = :key");
    query.bindValue(":key", key.toString());
    query.exec();
}
