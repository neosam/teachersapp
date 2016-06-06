#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include "school.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->main->setCurrentIndex(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::activateClasses()
{
    ui->main->setCurrentIndex(1);
}

void MainWindow::activateLessons()
{
    ui->main->setCurrentIndex(3);
}

void MainWindow::activateSchedule()
{
    ui->main->setCurrentIndex(4);
}

void MainWindow::addSchoolAction()
{
    QString name = QInputDialog::getText(this,
                                         tr("Schule hinzufügen"),
                                         tr("Schulname"));
    School school(name);
    school.save();
    emit(schoolAdded(school));
}

void MainWindow::showClassDetails(SchoolClass schoolClass)
{
    ui->schoolClassDetails->setSchoolClass(schoolClass);
    ui->main->setCurrentIndex(2);
}
