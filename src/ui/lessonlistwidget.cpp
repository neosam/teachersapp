#include "lessonlistwidget.h"
#include "ui_lessonlistwidget.h"
#include <QtSql>
#include <QInputDialog>
#include <QDebug>

LessonListWidget::LessonListWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LessonListWidget)
{
    ui->setupUi(this);
    model = new QSqlTableModel();
    model->setTable("school_subject");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    model->setHeaderData(1, Qt::Horizontal, tr("Schulfach"));
    ui->lessonList->setModel(model);
    ui->lessonList->hideColumn(0);
}

LessonListWidget::~LessonListWidget()
{
    delete ui;
}

void LessonListWidget::addLesson()
{
    QString lesson = QInputDialog::getText(this,
                                         tr("Fach hinzufügen"),
                                         tr("Fach"));
    QSqlRecord rec;
    QSqlField keyField("school_subject_key", QVariant::String);
    keyField.setValue(QUuid::createUuid().toString());
    QSqlField nameField("subject_name", QVariant::String);
    nameField.setValue(lesson);
    rec.append(keyField);
    rec.append(nameField);
    if (!model->insertRecord(-1, rec)) {
        qDebug() << "LessonListWidget::addLesson insert failed:  driver:  "
                 << model->lastError().driverText() << " - db: "
                 << model->lastError().databaseText();
    }
    model->submitAll();
    model->select();
}
