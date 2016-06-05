CREATE TABLE `school_subject` (
	`school_subject_key`	BLOB NOT NULL,
	`subject_name`	INTEGER NOT NULL,
	PRIMARY KEY(school_subject_key)
);
CREATE TABLE `lesson` (
	`lesson_key`	BLOB NOT NULL,
	`school_class_fk`	BLOB NOT NULL UNIQUE,
	`school_subject_fk`	BLOB NOT NULL UNIQUE,
	PRIMARY KEY(lesson_key),
	FOREIGN KEY(`school_class_fk`) REFERENCES school_class,
	FOREIGN KEY(`school_subject_fk`) REFERENCES school_subject
);
CREATE TABLE "pupil" (
	`pupil_key`	BLOB NOT NULL,
	`pupil_forename`	TEXT NOT NULL,
	`pupil_lastname`	TEXT NOT NULL,
	`school_class_fk`	BLOB,
	PRIMARY KEY(pupil_key),
	FOREIGN KEY(`school_class_fk`) REFERENCES school_class
);
CREATE TABLE "lesson_schedule" (
	`lesson_schedule_key`	BLOB NOT NULL,
	`timeslot_num`	INTEGER NOT NULL,
	`day_of_week`	TEXT NOT NULL,
	`time_start`	INTEGER NOT NULL,
	`time_end`	INTEGER NOT NULL,
	`recurrent`	INTEGER NOT NULL,
	`lesson_fk`	BLOB NOT NULL,
	PRIMARY KEY(lesson_schedule_key),
	FOREIGN KEY(`lesson_fk`) REFERENCES `lesson`
);
CREATE TABLE `assessment_criteria` (
	`assessment_criteria_key`	BLOB NOT NULL,
	`main_criteria`	TEXT NOT NULL UNIQUE,
	`detail_crateria`	TEXT NOT NULL UNIQUE,
	PRIMARY KEY(assessment_criteria_key)
);
CREATE TABLE `assessment` (
	`assessment_key`	BLOB NOT NULL,
	`free_text`	TEXT,
	`lesson_item_fk`	BLOB UNIQUE,
	`pupil_fk`	BLOB UNIQUE,
	PRIMARY KEY(assessment_key),
	FOREIGN KEY(`lesson_item_fk`) REFERENCES lesson_item,
	FOREIGN KEY(`pupil_fk`) REFERENCES pupil
);
CREATE TABLE `assessment_grade` (
	`assessment_grade_key`	BLOB NOT NULL,
	`assessment_fk`	BLOB NOT NULL UNIQUE,
	`assessment_criteria_fk`	BLOB NOT NULL UNIQUE,
	`grade`	INTEGER NOT NULL,
	PRIMARY KEY(assessment_grade_key)
);
CREATE TABLE `grade` (
	`grade_key`	BLOB NOT NULL,
	`grade`	INTEGER NOT NULL,
	`lesson_item_fk`	BLOB NOT NULL,
	`pupil_fk`	BLOB NOT NULL,
	PRIMARY KEY(grade_key),
	FOREIGN KEY(`lesson_item_fk`) REFERENCES lesson_item,
	FOREIGN KEY(`pupil_fk`) REFERENCES pupil
);
CREATE TABLE `test` (
	`test_key`	BLOB NOT NULL,
	`test_name`	TEXT NOT NULL,
	PRIMARY KEY(test_key)
);
CREATE TABLE `test_grade` (
	`test_grade_key`	BLOB NOT NULL,
	`test_fk`	BLOB NOT NULL,
	`grade_fk`	BLOB NOT NULL,
	PRIMARY KEY(test_grade_key),
	FOREIGN KEY(`test_fk`) REFERENCES test,
	FOREIGN KEY(`grade_fk`) REFERENCES grade
);
CREATE TABLE `presence` (
	`presence`	BLOB NOT NULL,
	`pupil_fk`	BLOB NOT NULL,
	`lesson_item_fk`	BLOB,
	PRIMARY KEY(presence),
	FOREIGN KEY(`pupil_fk`) REFERENCES pupil,
	FOREIGN KEY(`lesson_item_fk`) REFERENCES lesson_item
);
CREATE TABLE "lesson_item" (
	`lesson_item_key`	BLOB NOT NULL,
	`lesson_schedule_fk`	BLOB NOT NULL,
	`lesson_date`	TEXT NOT NULL,
	PRIMARY KEY(lesson_item_key),
	FOREIGN KEY(`lesson_schedule_fk`) REFERENCES `lesson_schedule`
);
CREATE VIEW v_school_class as
select school.school_name, school_class.class_label
from school
inner join school_class
on school.school_kew = school_class.school_fk;
CREATE TABLE "school" (
	`school_key`	BLOB NOT NULL,
	`school_name`	TEXT NOT NULL,
	PRIMARY KEY(school_key)
);
CREATE TABLE "school_class" (
	`school_class_key`	BLOB NOT NULL,
	`class_label`	TEXT NOT NULL,
	`school_fk`	BLOB NOT NULL,
	PRIMARY KEY(school_class_key),
	FOREIGN KEY(`school_fk`) REFERENCES school
);
