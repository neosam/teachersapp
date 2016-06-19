#-------------------------------------------------
#
# Project created by QtCreator 2016-06-01T18:41:11
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = teachersapp
TEMPLATE = app

GIT_VERSION = $$system(git --git-dir $$PWD/.git --work-tree $$PWD describe --always --tags --dirty)
DEFINES += GIT_VERSION=\\\"$$GIT_VERSION\\\"

SOURCES += src/main.cpp\
    src/ui/mainwindow.cpp \
    src/dataio.cpp \
    src/model/school.cpp \
    src/model/pupil.cpp \
    src/ui/schoolclasswidget.cpp \
    src/ui/classselectionwidget.cpp \
    src/model/schoolclass.cpp \
    src/ui/schoolclassitemwidget.cpp \
    src/ui/classdetailwidget.cpp \
    src/ui/pupiltablemodel.cpp \
    src/ui/lessonlistwidget.cpp \
    src/ui/lessonschedulemodel.cpp \
    src/model/lesson.cpp \
    src/ui/addscheduledialog.cpp \
    src/model/schoolsubject.cpp \
    src/ui/lessonschedulewidget.cpp \
    src/model/lessonschedule.cpp

HEADERS  += src/ui/mainwindow.h \
    src/dataio.h \
    src/model/school.h \
    src/model/pupil.h \
    src/ui/schoolclasswidget.h \
    src/ui/classselectionwidget.h \
    src/model/schoolclass.h \
    src/ui/schoolclassitemwidget.h \
    src/ui/classdetailwidget.h \
    src/ui/pupiltablemodel.h \
    src/ui/lessonlistwidget.h \
    src/ui/lessonschedulemodel.h \
    src/model/lesson.h \
    src/ui/addscheduledialog.h \
    src/model/schoolsubject.h \
    src/ui/lessonschedulewidget.h \
    src/model/lessonschedule.h

FORMS    += src/ui/mainwindow.ui \
    src/ui/schoolclasswidget.ui \
    src/ui/schoolclassitemwidget.ui \
    src/ui/classdetailwidget.ui \
    src/ui/lessonlistwidget.ui \
    src/ui/addscheduledialog.ui \
    src/ui/lessonschedulewidget.ui
