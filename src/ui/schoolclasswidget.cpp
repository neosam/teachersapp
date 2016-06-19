#include "schoolclasswidget.h"
#include "ui_schoolclasswidget.h"
#include "src/model/schoolclass.h"

#include <QInputDialog>
#include "schoolclassitemwidget.h"

SchoolClassWidget::SchoolClassWidget(School school, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SchoolClassWidget),
    school(School(""))
{
    ui->setupUi(this);
    classesLayout = new QVBoxLayout(ui->classesView);
    this->school = school;
    ui->nameLabel->setText(school.getSchoolName());

    foreach (SchoolClass schoolClass, SchoolClass::classesInSchool(school)) {
        insertSchoolClass(schoolClass);
    }
}

SchoolClassWidget::~SchoolClassWidget()
{
    delete ui;
}

void SchoolClassWidget::removeSchool()
{
    school.remove();
}

void SchoolClassWidget::addClass()
{
    QString label = QInputDialog::getText(this,
                                         tr("Klasse hinzufügen"),
                                         tr("Klassenname"));
    SchoolClass schoolClass(label, school.getKey().toString());
    schoolClass.save();
    emit(schoolClassAdded(schoolClass));
}

void SchoolClassWidget::insertSchoolClass(SchoolClass schoolClass)
{
    SchoolClassItemWidget *w = new SchoolClassItemWidget(schoolClass);
    connect(w, SIGNAL(openSchoolClass(SchoolClass)), this, SLOT(triggerOpenSchoolClass(SchoolClass)));
    classesLayout->addWidget(w);
}

void SchoolClassWidget::triggerOpenSchoolClass(SchoolClass schoolClass)
{
    emit(openSchoolClass(schoolClass));
}
