#include "lessonlistwidget.h"
#include "ui_lessonlistwidget.h"

LessonListWidget::LessonListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LessonListWidget)
{
    ui->setupUi(this);
   // model = new QSqlTableModel();
}

LessonListWidget::~LessonListWidget()
{
    delete ui;
}
