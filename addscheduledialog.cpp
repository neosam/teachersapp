#include "addscheduledialog.h"
#include "ui_addscheduledialog.h"

#include "schoolsubject.h"

AddScheduleDialog::AddScheduleDialog(int weekday, int lessonCount, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddScheduleDialog)
{
    ui->setupUi(this);
    this->weekday = weekday;
    this->lessonCount = lessonCount;

    ui->dayLabel->setText(getWeekdayString());
    ui->lessonNumLabel->setText(QVariant(lessonCount + 1).toString());

    foreach(SchoolSubject subject, SchoolSubject::all()) {
        ui->lessonBox->addItem(subject.getName(), subject.getKey());
    }
}

AddScheduleDialog::~AddScheduleDialog()
{
    delete ui;
}

QString AddScheduleDialog::getWeekdayString() const {
    switch(weekday) {
    case 0: return QString(tr("Montag"));
    case 1: return QString(tr("Dienstag"));
    case 2: return QString(tr("Mittwoch"));
    case 3: return QString(tr("Donnerstag"));
    case 4: return QString(tr("Freitag"));
    case 5: return QString(tr("Samstag"));
    case 6: return QString(tr("Sonntag"));
    default: return QString(tr(""));
    }
}

SchoolSubject AddScheduleDialog::selectedSubject() const {
    QUuid subjectKey = ui->lessonBox->currentData().toUuid();
    SchoolSubject subject = SchoolSubject::forKey(subjectKey);
    return subject;
}
