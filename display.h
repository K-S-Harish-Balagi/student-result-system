#ifndef DISPLAY_H
#define DISPLAY_H
#include "student.h"

void printReport(FILE* fp, Student s[], int n);
void printStatistics(FILE* fp, Student s[], int n);
void printGradeList(FILE* fp, Student s[], int n);
#endif
