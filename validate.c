#include "validate.h"
#include <stdio.h>
#include <string.h>

int isAlphanumeric(char s[]) {
    for (int i = 0; s[i]; i++) {
        char ch = s[i];
        if (!((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') ||
              (ch >= 'a' && ch <= 'z')))
            return 0;
    }
    return 1;
}

int isUniqueID(Student s[], int count, char id[]) {
    for (int i = 0; i < count; i++)
        if (strcmp(s[i].id, id) == 0) return 0;
    return 1;
}

int isValidName(char name[]) {
    for (int i = 0; name[i]; i++) {
        char ch = name[i];
        if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))) 
            return 0;
    }
    return 1;
}

int isValidMarks(int minor, int major) {
    return (minor >= 0 && minor <= 40 && major >= 0 && major <= 60);
}
