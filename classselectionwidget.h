#ifndef CLASSSELECTIONWIDGET_H
#define CLASSSELECTIONWIDGET_H

#include <QWidget>
#include "school.h"
#include "schoolclass.h"

class ClassSelectionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ClassSelectionWidget(QWidget *parent = 0);

signals:
    void openSchoolClass(SchoolClass);

public slots:
    void addSchool(School school);
    void triggerOpenSchoolClass(SchoolClass SchoolClass);
};

#endif // CLASSSELECTIONWIDGET_H
