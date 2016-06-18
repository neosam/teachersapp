#include "dataio.h"
#include <QtSql>
#include <QDebug>

DataIO::DataIO(QObject *parent) : QObject(parent)
{
    // Start database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db3");
    if (!db.open()) {
        qDebug() << "Could not open database";
    }
}
