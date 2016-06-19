#include "src/ui/mainwindow.h"
#include "dataio.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    qDebug() << "Running version " << GIT_VERSION;
    QApplication a(argc, argv);
    DataIO dataIO;
    MainWindow w;
    w.setWindowTitle(QString("Lehrerapp - Version: ") + QString(GIT_VERSION));
    w.show();

    return a.exec();
}
