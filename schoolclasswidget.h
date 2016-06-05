#ifndef SCHOOLCLASSWIDGET_H
#define SCHOOLCLASSWIDGET_H

#include <QWidget>
#include "school.h"
#include "schoolclass.h"
#include "QVBoxLayout"

namespace Ui {
class SchoolClassWidget;
}

class SchoolClassWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SchoolClassWidget(School school, QWidget *parent = 0);
    ~SchoolClassWidget();

private:
    Ui::SchoolClassWidget *ui;
    School school;
    QVBoxLayout *classesLayout;

public slots:
    void removeSchool();
    void addClass();
    void insertSchoolClass(SchoolClass schoolClass);
    void triggerOpenSchoolClass(SchoolClass schoolClass);

signals:
    void schoolClassAdded(SchoolClass);
    void openSchoolClass(SchoolClass);
};

#endif // SCHOOLCLASSWIDGET_H
