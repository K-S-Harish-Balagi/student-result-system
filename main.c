#include <stdio.h>
#include "compute.h"
#include "errorhandler.h"
#include "student.h"
#include "validate.h"

#define MAX 100

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Error opening file name %s", argv[1]);
        return 2;
    }

    Student s[MAX];
    int count = 0;
    int skip = 0;
    while (fscanf(fp, "%s %s", s[count].id, s[count].name) == 2) {
        skip = 0;
        if (!isAlphanumeric(s[count].id)) {
            printError(s[count].id, "ID must be alphanumeric");
            if (askSkip(fp)) continue;
            return 1;
        }

        if (!isUniqueID(s, count, s[count].id)) {
            printError(s[count].id, "Duplicate ID found");
            if (askSkip(fp)) continue;
            return 1;
        }

        if (!isValidName(s[count].name)) {
            printError(s[count].id, "Name must contain only letters");
            if (askSkip(fp)) continue;
            return 1;
        }

        for (int j = 0; j < SUBJECTS; j++) {
            fscanf(fp, "%s %d %d", s[count].subjects[j].name,
                   &s[count].subjects[j].minor, &s[count].subjects[j].major);

            if (!isValidMarks(s[count].subjects[j].minor, s[count].subjects[j].major)) {
                printError(s[count].id, "Invalid marks (minor 0–40, major 0–60)");
                if (askSkip(fp)) {
                    skip = 1;
                    break;
                }
                return 1;
            }
        }
        if(skip == 0){
        computeResult(&s[count]);
        count++;
        }
    }

    fclose(fp);

    FILE* out = fopen(argv[2],"w");
    if (!out) {
        fprintf(stderr, "Error writing file name %s", argv[2]);
        return 3;
    }

    printReport(out,s, count);
    printStatistics(out, s, count);

    fclose(out);
    return 0;
}