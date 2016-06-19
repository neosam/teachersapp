#include "classdetailwidget.h"
#include "ui_classdetailwidget.h"
#include <QPushButton>
#include <QInputDialog>
#include "pupiltablemodel.h"

ClassDetailWidget::ClassDetailWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClassDetailWidget),
    schoolClass(SchoolClass("", QUuid()))
{
    ui->setupUi(this);
    //ui->pupilView->setModel(new PupilTableModel(QList<Pupil>()));
    model = new QSqlTableModel(this, QSqlDatabase::database());
    model->setTable("pupil");
    model->setHeaderData(1, Qt::Horizontal, tr("Vorname"));
    model->setHeaderData(2, Qt::Horizontal, tr("Nachname"));
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->setSort(1, Qt::AscendingOrder);
    ui->pupilView->setModel(model);
    ui->pupilView->hideColumn(0);
    ui->pupilView->hideColumn(3);
}

ClassDetailWidget::~ClassDetailWidget()
{
    delete ui;
}

void ClassDetailWidget::setSchoolClass(SchoolClass schoolClass)
{
    ui->title->setText(schoolClass.getLabel());
    QList<Pupil> pupilList = Pupil::fromClass(schoolClass);
    model->setFilter("school_class_fk = '" + schoolClass.getKey().toString() + "'");
    model->select();
    this->schoolClass = schoolClass;
}


void ClassDetailWidget::newPupil()
{
    QString forename = QInputDialog::getText(this,
                                         tr("Schüler hinzufügen"),
                                         tr("Vorname"));
    QString lastname = QInputDialog::getText(this,
                                         tr("Schüler hinzufügen"),
                                         tr("Nachame"));
    Pupil pupil(forename, lastname, schoolClass.getKey());
    pupil.save();
    model->select();
    //emit(pupilAdded(pupil));
    //PupilTableModel *model = (PupilTableModel *) ui->pupilView->model();
    //model->addPupil(pupil);
}
