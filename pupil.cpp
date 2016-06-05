#include "pupil.h"
#include <QtSql>
#include <QDebug>
#include <QList>

Pupil::Pupil(QString forename, QString lastname, QUuid classKey)
{
    this->key = QUuid::createUuid();
    this->forename = forename;
    this->lastname = lastname;
    this->classKey = classKey;
}
Pupil::Pupil(QUuid key,
             QString forename, QString lastname, QUuid classKey)
{
    this->key = key;
    this->forename = forename;
    this->lastname = lastname;
    this->classKey = classKey;
}


void Pupil::save()
{
    QSqlQuery q;
    q.prepare("INSERT OR REPLACE INTO pupil "
              "(pupil_key, pupil_forename, pupil_lastname, school_class_fk) "
              "VALUES "
              "(:key, :forename, :lastname, :schoolClass)");
    q.bindValue(":key", key.toString());
    q.bindValue(":forename", forename);
    q.bindValue(":lastname", lastname);
    q.bindValue(":schoolClass", classKey.toString());
    if (!q.exec()) {
        qDebug() << "Pupil::save SQL error:  "
                 << q.lastError().driverText()
                 << " - " << q.lastError().databaseText();
    }
}

QList<Pupil> Pupil::fromClass(SchoolClass schoolClass)
{
    QList<Pupil> res;
    QSqlQuery q;
    q.prepare("SELECT pupil_key, pupil_forename, pupil_lastname, school_class_fk "
              "FROM pupil "
              "WHERE school_class_fk = :key");
    q.bindValue(":key", schoolClass.getKey().toString());
    if (q.exec()) {
       while (q.next()) {
           Pupil pupil(QUuid(q.value("pupil_key").toString()),
                       q.value("pupil_forename").toString(),
                       q.value("pupil_lastname").toString(),
                       schoolClass.getKey());
           res.append(pupil);
       }
    } else {
        qDebug() << "Pupil::fromClass SQL error:  "
                 << q.lastError().driverText();
    }
    return res;
}
