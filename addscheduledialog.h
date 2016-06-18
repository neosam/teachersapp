#ifndef ADDSCHEDULEDIALOG_H
#define ADDSCHEDULEDIALOG_H

#include <QDialog>

namespace Ui {
class AddScheduleDialog;
}

class AddScheduleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddScheduleDialog(QWidget *parent = 0);
    ~AddScheduleDialog();

private:
    Ui::AddScheduleDialog *ui;
};

#endif // ADDSCHEDULEDIALOG_H
