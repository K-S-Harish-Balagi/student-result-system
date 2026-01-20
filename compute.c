#include "compute.h"

#include <string.h>

#include "student.h"



static void assignSubjectGrade(Subject* sub) {
    int t = sub->total;

    if (t >= 90) {
        strcpy(sub->grade, "O");
        sub->gradePoint = 10;
    } else if (t >= 85) {
        strcpy(sub->grade, "A+");
        sub->gradePoint = 9;
    } else if (t >= 75) {
        strcpy(sub->grade, "A");
        sub->gradePoint = 8;
    } else if (t >= 65) {
        strcpy(sub->grade, "B+");
        sub->gradePoint = 7;
    } else if (t >= 60) {
        strcpy(sub->grade, "B");
        sub->gradePoint = 6;
    } else if (t >= 55) {
        strcpy(sub->grade, "C");
        sub->gradePoint = 5;
    } else if (t >= 50) {
        strcpy(sub->grade, "D");
        sub->gradePoint = 4;
    } else {
        strcpy(sub->grade, "F");
        sub->gradePoint = 0;
    }
}

void computeResult(Student* s) {
    s->totalMarks = 0;
    int totalGP = 0;
    int pass = 1;

    for (int i = 0; i < SUBJECTS; i++) {
        s->subjects[i].total = s->subjects[i].minor + s->subjects[i].major;
        s->totalMarks += s->subjects[i].total;
        assignSubjectGrade(&s->subjects[i]);
        totalGP += s->subjects[i].gradePoint;
        if (s->subjects[i].total < 50) pass = 0;
    }
    s->percentage = s->totalMarks / (float)SUBJECTS;
    if (pass)
        s->cgpa = totalGP / (float)SUBJECTS;
    else
        s->cgpa = 0.0;
}


void SubjectGradecount(Subject* sub, int gradecount[][GRADES], int subjectno) {

    if (sub->gradePoint == 10) {
        gradecount[subjectno][O]++;
    } else if (sub->gradePoint == 9) {
        gradecount[subjectno][A_Plus]++;
    } else if (sub->gradePoint == 8) {
        gradecount[subjectno][A]++;
    } else if (sub->gradePoint == 7) {
        gradecount[subjectno][B_Plus]++;
    } else if (sub->gradePoint == 6) {
        gradecount[subjectno][B]++;
    } else if (sub->gradePoint == 5) {
        gradecount[subjectno][C]++;
    } else if (sub->gradePoint == 4) {
        gradecount[subjectno][D]++;
    } else {
        gradecount[subjectno][F]++;
    }
}
