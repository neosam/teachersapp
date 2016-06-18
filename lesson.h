#ifndef LESSON_H
#define LESSON_H

#include <QString>
#include <QUuid>

class Lesson
{
private:
    QUuid key;
    QUuid schoolLessonKey;
    QUuid schoolClassKey;

    QString lessonName;
    QString className;
    QString schoolName;

public:
    Lesson();


};

#endif // LESSON_H
