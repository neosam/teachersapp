#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "school.h"
#include "schoolclass.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void activateClasses();
    void activateLessons();
    void addSchoolAction();
    void showClassDetails(SchoolClass schoolClass);

signals:
    void schoolAdded(School);
};

#endif // MAINWINDOW_H
