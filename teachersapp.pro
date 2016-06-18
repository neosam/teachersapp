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

SOURCES += main.cpp\
        mainwindow.cpp \
    dataio.cpp \
    school.cpp \
    pupil.cpp \
    schoolclasswidget.cpp \
    classselectionwidget.cpp \
    schoolclass.cpp \
    schoolclassitemwidget.cpp \
    classdetailwidget.cpp \
    pupiltablemodel.cpp \
    lessonlistwidget.cpp \
    lessonschedulemodel.cpp \
    lessonschedule.cpp \
    lesson.cpp \
    addscheduledialog.cpp

HEADERS  += mainwindow.h \
    dataio.h \
    school.h \
    pupil.h \
    schoolclasswidget.h \
    classselectionwidget.h \
    schoolclass.h \
    schoolclassitemwidget.h \
    classdetailwidget.h \
    pupiltablemodel.h \
    lessonlistwidget.h \
    lessonschedulemodel.h \
    lessonschedule.h \
    lesson.h \
    addscheduledialog.h

FORMS    += mainwindow.ui \
    schoolclasswidget.ui \
    schoolclassitemwidget.ui \
    classdetailwidget.ui \
    lessonlistwidget.ui \
    lessonschedule.ui \
    addscheduledialog.ui
