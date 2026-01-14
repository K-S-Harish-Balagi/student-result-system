#ifndef STUDENT_H
#define STUDENT_H

#define SUBJECTS 5
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

void printReport(FILE* fp, Student s[], int n);
void printStatistics(FILE* fp, Student s[], int n);

#endif
