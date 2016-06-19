#ifndef LESSONSCHEDULE_H
#define LESSONSCHEDULE_H

#include <QWidget>
#include "lessonschedulemodel.h"

namespace Ui {
class LessonScheduleWidget;
}

class LessonScheduleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LessonScheduleWidget(QWidget *parent = 0);
    ~LessonScheduleWidget();

private:
    Ui::LessonScheduleWidget *ui;
    LessonScheduleModel *model;

public slots:
    void editEntry(QModelIndex index);
};

#endif // LESSONSCHEDULE_H
