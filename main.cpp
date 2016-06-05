#include "mainwindow.h"
#include "school.h"
#include "dataio.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataIO dataIO;
    MainWindow w;
    w.show();

    return a.exec();
}
