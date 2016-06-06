#ifndef LESSONSCHEDULE_H
#define LESSONSCHEDULE_H

#include <QWidget>
#include "lessonschedulemodel.h"

namespace Ui {
class LessonSchedule;
}

class LessonSchedule : public QWidget
{
    Q_OBJECT

public:
    explicit LessonSchedule(QWidget *parent = 0);
    ~LessonSchedule();

private:
    Ui::LessonSchedule *ui;
    LessonScheduleModel *model;
};

#endif // LESSONSCHEDULE_H
