#include "schoolclassitemwidget.h"
#include "ui_schoolclassitemwidget.h"

SchoolClassItemWidget::SchoolClassItemWidget(SchoolClass schoolClass, QWidget *parent) :
    QWidget(parent),
    schoolClass(schoolClass),
    ui(new Ui::SchoolClassItemWidget)
{
    ui->setupUi(this);
    ui->classLabel->setText(schoolClass.getLabel());
}

SchoolClassItemWidget::~SchoolClassItemWidget()
{
    delete ui;
}

void SchoolClassItemWidget::removeSchoolClass()
{
    schoolClass.remove();
}

void SchoolClassItemWidget::triggerOpenSchoolClass()
{
    emit(openSchoolClass(schoolClass));
}
