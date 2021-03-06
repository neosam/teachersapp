#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "src/model/school.h"
#include "src/model/schoolclass.h"

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
    void activateSchedule();
    void addSchoolAction();
    void showClassDetails(SchoolClass schoolClass);

signals:
    void schoolAdded(School);
};

#endif // MAINWINDOW_H
