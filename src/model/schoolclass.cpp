#include "schoolclass.h"
#include <QtSql>
#include <QDebug>

SchoolClass::SchoolClass(QString label, QUuid schoolKey)
{
    key = QUuid::createUuid();
    this->label = label;
    this->schoolKey = schoolKey;
}

SchoolClass::SchoolClass(QUuid key, QString label, QUuid schoolKey)
{
    this->key = key;
    this->label = label;
    this->schoolKey = schoolKey;
}

void SchoolClass::save()
{
    QSqlQuery query;
    query.prepare("INSERT OR REPLACE INTO school_class "
                  "(school_class_key, class_label, school_fk) "
                  "VALUES "
                  "(:key, :label, :fk)");
    query.bindValue(":key", key.toString());
    query.bindValue(":label", label);
    query.bindValue(":fk", schoolKey.toString());
    if (!query.exec()) {
        qDebug() << "SchoolClass::save SQL error:  "
                 << query.lastError().driverText()
                 << " - key:  "
                 << key.toString();
    }
}

void SchoolClass::remove()
{
    QSqlQuery query;
    query.prepare("DELETE FROM school_class "
                  "WHERE school_class_key = :key");
    query.bindValue(":key", key.toString());
    if (!query.exec()) {
        qDebug() << "SchoolClass::remove SQL error:  "
                 << query.lastError().driverText()
                 << " - key:  "
                 << key.toString();
    }
}


QList<SchoolClass> SchoolClass::classesInSchool(School school)
{
    QList<SchoolClass> res;
    QSqlQuery query;
    query.prepare("SELECT school_class_key, class_label, school_fk "
                  "FROM school_class "
                  "WHERE school_fk = :key");
    query.bindValue(":key", school.getKey().toString());
    if (!query.exec()) {
        qDebug() << "SchoolClass::classesInSchool SQL error: "
                 << query.lastError().driverText()
                 << " school key:  "
                 << school.getKey().toString();
    }
    while(query.next()) {
        SchoolClass schoolClass(QUuid(query.value("school_class_key").toString()),
                      query.value("class_label").toString(), school.getKey());
        res.append(schoolClass);
    }
    return res;
}
