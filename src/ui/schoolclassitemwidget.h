#ifndef SCHOOLCLASSITEMWIDGET_H
#define SCHOOLCLASSITEMWIDGET_H

#include <QWidget>
#include "src/model/schoolclass.h"

namespace Ui {
class SchoolClassItemWidget;
}

class SchoolClassItemWidget : public QWidget
{
    Q_OBJECT
    SchoolClass schoolClass;

public:
    explicit SchoolClassItemWidget(SchoolClass schoolClass, QWidget *parent = 0);
    ~SchoolClassItemWidget();

private:
    Ui::SchoolClassItemWidget *ui;

public slots:
    void removeSchoolClass();
    void triggerOpenSchoolClass();

signals:
    void openSchoolClass(SchoolClass);
};

#endif // SCHOOLCLASSITEMWIDGET_H
