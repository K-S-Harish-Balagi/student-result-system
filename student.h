#ifndef STUDENT_H
#define STUDENT_H

#define SUBJECTS 5
#define GRADES 8
#include <stdio.h>

typedef struct {
    char name[20];
    int minor;
    int major;
    int total;
    char grade[3];
    int gradePoint;
} Subject;

typedef struct {
    char id[20];
    char name[50];
    Subject subjects[5];
    int totalMarks;
    float percentage;
    float cgpa;
} Student;

typedef enum{
    O,
    A_Plus,
    A,
    B_Plus,
    B,
    C,
    D,
    F,
} Grades;


#endif
