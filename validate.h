#ifndef VALIDATE_H
#define VALIDATE_H

#include "student.h"

int isAlphanumeric(char s[]);
int isUniqueID(Student s[], int count, char id[]);
int isValidName(char name[]);
int isValidMarks(int minor, int major);

#endif
