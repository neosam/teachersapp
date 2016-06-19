#ifndef LESSONSCHEDULE_H
#define LESSONSCHEDULE_H

#include <QUuid>
#include <QString>

class LessonSchedule
{
private:
    QUuid key;
    qint8 lessonNum;
    qint8 weekday;
    QUuid lessonKey;

public:
    LessonSchedule(): key(QUuid()), lessonNum(-1), weekday(-1), lessonKey(QUuid()) {}
    LessonSchedule(QUuid key, qint8 lessonNum, qint8 weekday, QUuid lessonKey):
        key(key), lessonNum(lessonNum), weekday(weekday), lessonKey(lessonKey) {}
};

#endif // LESSONSCHEDULE_H
