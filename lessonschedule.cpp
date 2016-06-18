#include "lessonschedule.h"
#include "ui_lessonschedule.h"

#include "addscheduledialog.h"

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
    AddScheduleDialog *dialog = new AddScheduleDialog(this);
    dialog->exec();
    dialog->deleteLater();
}
