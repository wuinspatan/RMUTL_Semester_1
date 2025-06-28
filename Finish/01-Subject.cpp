#include <stdio.h>
#include <string.h>

#define MAX_SUBJECTS 4

struct S {
    char name[32] ;
    char semester[2] ;
    unsigned int CountSubject;

    char code[MAX_SUBJECTS][10];
    char SubjectName[MAX_SUBJECTS][20];
    int unit[MAX_SUBJECTS];
    int point[MAX_SUBJECTS];
};

void getData(struct S *subject) ;
void getSubjectData(struct S *subject, int subjectCount) ;
const char* getGrade(int point) ;
void calculateAverageGrade(struct S *subject) ;
void ShowData(struct S subject) ;


int main() {

    struct S subject;
    getData(&subject);
    getSubjectData(&subject, subject.CountSubject);
    ShowData(subject);                                        
    calculateAverageGrade(&subject);

    return 0;
}//end main

void getData(struct S *subject) {
    printf("Enter your name: ");
    fgets(subject->name, sizeof(subject->name), stdin);
    subject->name[strcspn(subject->name, "\n")] = '\0';

    printf("Enter semester: ");
    scanf("%3s", subject->semester); 

    printf("Enter total subjects: ");
    scanf("%u", &subject->CountSubject);
}//end getData Func


void getSubjectData(struct S *subject, int subjectCount) {
    for (int i = 0; i < subjectCount; i++) {
        printf("\nEnter CODE subject [%d]: ", i + 1);
        scanf("%s", subject->code[i]);  
        printf("Enter NAME subject : ");
        scanf("%s", subject->SubjectName[i]);  
        printf("Enter UNIT subject : ");
        scanf("%d", &subject->unit[i]);
        printf("Enter your SCORE subject : ");
        scanf("%d", &subject->point[i]);
    }
}//end getSubject func

const char* getGrade(int point) {
    if (point >= 80) return "A";
    else if (point >= 75) return "B+";
    else if (point >= 70) return "B";
    else if (point >= 65) return "C+";
    else if (point >= 60) return "C";
    else if (point >= 55) return "D+";
    else if (point >= 50) return "D";
    else return "F";
}//end show grade func

void calculateAverageGrade(struct S *subject) {
    int totalPoints = 0;
    printf("\n");
    for (int i = 0; i < subject->CountSubject; i++) {
        totalPoints += subject->point[i];
        printf("Grade for subject %d (%s): %s\n", i + 1, subject->SubjectName[i], getGrade(subject->point[i]));
    }

    float average = totalPoints / (float)subject->CountSubject;
    // printf("\nAverage Score: %.2f\n", average);
    printf("Average Grade: %s\n", getGrade((int)average));
}//end calculateAVG_GPA func

void ShowData(struct S subject) {
    printf("\n===== Data infomation =====\n");
    printf("\nNAME: %s\n", subject.name);
    printf("SEMESTER: %s\n", subject.semester);
    printf("TOTAL SUBJECTS: %u\n", subject.CountSubject);

    for (int i = 0; i < subject.CountSubject; i++) {
        printf("\nSubject %d: %s\n", i + 1, subject.SubjectName[i]);
        printf("Code: %s\n", subject.code);
        printf("Unit: %d\n", subject.unit[i]);
        printf("Score: %d\n", subject.point[i]);
        printf("Grade: %s\n", getGrade(subject.point[i]));
    }
}//end ShowData func