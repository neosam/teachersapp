#ifndef CLASSDETAILWIDGET_H
#define CLASSDETAILWIDGET_H

#include <QWidget>
#include "schoolclass.h"
#include "pupil.h"
#include <QtSql>

namespace Ui {
class ClassDetailWidget;
}

class ClassDetailWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClassDetailWidget(QWidget *parent = 0);
    ~ClassDetailWidget();

    void setSchoolClass(SchoolClass schoolClass);

private:
    Ui::ClassDetailWidget *ui;
    SchoolClass schoolClass;
    QSqlTableModel *model;

public slots:
    void newPupil();

signals:
    void pupilAdded(Pupil);
};

#endif // CLASSDETAILWIDGET_H
