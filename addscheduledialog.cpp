#include "addscheduledialog.h"
#include "ui_addscheduledialog.h"

AddScheduleDialog::AddScheduleDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScheduleDialog)
{
    ui->setupUi(this);
}

AddScheduleDialog::~AddScheduleDialog()
{
    delete ui;
}
