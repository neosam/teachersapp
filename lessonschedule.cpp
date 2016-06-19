#include "lessonschedule.h"
#include "ui_lessonschedule.h"

#include "addscheduledialog.h"
#include "schoolsubject.h"
#include <QDebug>

LessonSchedule::LessonSchedule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LessonSchedule)
{
    ui->setupUi(this);
    model = new LessonScheduleModel();
    ui->scheduleTable->setModel(model);
}

LessonSchedule::~LessonSchedule()
{
    delete ui;
}

void LessonSchedule::editEntry(QModelIndex index)
{
    AddScheduleDialog *dialog = new AddScheduleDialog(index.column(), index.row(), this);
    dialog->exec();
    dialog->deleteLater();
    SchoolSubject subject = dialog->selectedSubject();
    qDebug() << subject.getName();
}
