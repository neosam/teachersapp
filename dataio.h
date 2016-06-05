#ifndef DATAIO_H
#define DATAIO_H

#include <QObject>

class DataIO : public QObject
{
    Q_OBJECT
public:
    explicit DataIO(QObject *parent = 0);

signals:

public slots:
};

#endif // DATAIO_H