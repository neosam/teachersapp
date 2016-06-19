#include "classselectionwidget.h"
#include "src/model/school.h"
#include <QList>
#include <QVBoxLayout>
#include <QLabel>
#include "schoolclasswidget.h"

ClassSelectionWidget::ClassSelectionWidget(QWidget *parent) : QWidget(parent)
{
    new QVBoxLayout(this);
    QList<School> schoolList = School::all();
    foreach (School school, schoolList) {
        addSchool(school);
    }
}

void ClassSelectionWidget::addSchool(School school)
{
    SchoolClassWidget *w = new SchoolClassWidget(school);
    layout()->addWidget(w);
    connect(w, SIGNAL(openSchoolClass(SchoolClass)),
            this, SLOT(triggerOpenSchoolClass(SchoolClass)));
}

void ClassSelectionWidget::triggerOpenSchoolClass(SchoolClass schoolClass)
{
    emit(openSchoolClass(schoolClass));
}
