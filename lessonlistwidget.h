#ifndef LESSONLISTWIDGET_H
#define LESSONLISTWIDGET_H

#include <QWidget>
#include <QtSql>

namespace Ui {
class LessonListWidget;
}

class LessonListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LessonListWidget(QWidget *parent = 0);
    ~LessonListWidget();

private:
    Ui::LessonListWidget *ui;
    QSqlTableModel *model;

};

#endif // LESSONLISTWIDGET_H
