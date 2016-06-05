#include "dataio.h"
#include <QtSql>

DataIO::DataIO(QObject *parent) : QObject(parent)
{
    // Start database connection
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db3");
    db.open();
}
