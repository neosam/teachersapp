#ifndef ADDSCHEDULEDIALOG_H
#define ADDSCHEDULEDIALOG_H

#include <QDialog>
#include "src/model/schoolsubject.h"

namespace Ui {
class AddScheduleDialog;
}

class AddScheduleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddScheduleDialog(int weekday, int lessonCount, QWidget *parent = 0);
    ~AddScheduleDialog();

    QString getWeekdayString() const;

    SchoolSubject selectedSubject() const;

private:
    Ui::AddScheduleDialog *ui;
    int weekday;
    int lessonCount;
};

#endif // ADDSCHEDULEDIALOG_H
