#include "errorhandler.h"

int askSkip(FILE* fp) {
    char choice;
    printf("Do you want to skip this record and continue? (press y to confirm ): ");
    scanf(" %c", &choice);  // space to skip \n
    if (choice == 'y' || choice == 'Y') {
        fscanf(fp, "%*[^\n]");
        fscanf(fp, "%*c");
        return 1;
    }
    return 0;
}

void printError(const char* id, const char* msg) {
    printf("Error in record with ID %s: %s\n", id, msg);
}
