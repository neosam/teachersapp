#include "lessonschedulewidget.h"
#include "ui_lessonschedulewidget.h"

#include "addscheduledialog.h"
#include "src/model/schoolsubject.h"
#include <QDebug>

LessonScheduleWidget::LessonScheduleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LessonScheduleWidget)
{
    ui->setupUi(this);
    model = new LessonScheduleModel();
    ui->scheduleTable->setModel(model);
}

LessonScheduleWidget::~LessonScheduleWidget()
{
    delete ui;
}

void LessonScheduleWidget::editEntry(QModelIndex index)
{
    AddScheduleDialog *dialog = new AddScheduleDialog(index.column(), index.row(), this);
    dialog->exec();
    dialog->deleteLater();
    SchoolSubject subject = dialog->selectedSubject();
    qDebug() << subject.getName();
    model->insert(index, subject);
}
