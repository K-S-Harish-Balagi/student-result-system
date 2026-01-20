#include "student.h"
#include "compute.h"


void printReport(FILE* fp, Student s[], int n) {
    fprintf(fp, "\n%-10s %-12s", "ID", "Name");
    for (int i = 0; i < SUBJECTS; i++) {
        fprintf(fp, "%-4s%-1d %-3s %-3s %-3s %-3s %-5s","Sub",i+1,"MIN","MAJ","TOT", "GRD", "GRDP");
    }
    fprintf(fp, " Total   Percent   CGPA\n");

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%-10s %-12s", s[i].id, s[i].name);

        for (int j = 0; j < SUBJECTS; j++) {
            fprintf(fp, "%-5s %-3d %-3d %-3d %-3s %-5d",
                    s[i].subjects[j].name, s[i].subjects[j].minor,
                    s[i].subjects[j].major, s[i].subjects[j].total,
                    s[i].subjects[j].grade, s[i].subjects[j].gradePoint);
        }

        fprintf(fp, " %-7d %-6.2f   %-4.2f\n", s[i].totalMarks, s[i].percentage,
                s[i].cgpa);
    }
}

void printStatistics(FILE* fp, Student s[], int n) {
    float sum = 0, max = s[0].percentage, min = s[0].percentage;

    for (int i = 0; i < n; i++) {
        sum += s[i].percentage;
        if (s[i].percentage > max) max = s[i].percentage;
        if (s[i].percentage < min) min = s[i].percentage;
    }

    fprintf(fp, "\nClass Average: %.2f%%\n", sum / n);
    fprintf(fp, "Highest Percentage: %.2f%%\n", max);
    fprintf(fp, "Lowest Percentage: %.2f%%\n", min);
}


void printGradeList(FILE* fp, Student s[], int n) {
    int gradecount[SUBJECTS][GRADES] = {0};
    fprintf(fp,"number of students for each grade per subject \n");
    fprintf(fp, "%-4s %-3s %-3s %-3s %-3s %-3s %-3s %-3s %-3s","Sub ","O","A+","A", "B+", "B", "C", "D", "F");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < SUBJECTS; j++) {
            SubjectGradecount(&s[i].subjects[j],gradecount, j);
        }
    }
    for (int i = 0; i < SUBJECTS; i++) {
        fprintf(fp, "\n%-3s",s[0].subjects[i].name);
        for(int j = 0; j < GRADES; j++){
            fprintf(fp,"%3d ",gradecount[i][j]);
        }
    }
    fprintf(fp,"\n");
}