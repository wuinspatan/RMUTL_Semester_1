#include <stdio.h>
#include <string.h>

#define MAX_SUBJECTS 4

// Struct definition
struct S {
    char name[32];
    char semester[3];
    unsigned int CountSubject;
    char code[MAX_SUBJECTS][10];
    char SubjectName[MAX_SUBJECTS][20];
    int Credit[MAX_SUBJECTS];
    int point[MAX_SUBJECTS];
};

// Function prototypes
void getData(struct S *subject);
void getSubjectData(struct S *subject, int subjectCount);
const char* getGrade(int point);
float gradeToPoint(const char *grade);
void calculateGradeCredit(struct S *subject);
void calculateAverageGrade(struct S *subject);
void ShowData(struct S subject);

// Main
int main() {
    struct S subject;
    getData(&subject);
    getSubjectData(&subject, subject.CountSubject);
    ShowData(subject);
    calculateAverageGrade(&subject);
    calculateGradeCredit(&subject);

    return 0;
}

// Input personal data
void getData(struct S *subject) {
    printf("Enter your name: ");
    fgets(subject->name, sizeof(subject->name), stdin);
    subject->name[strcspn(subject->name, "\n")] = '\0';

    printf("Enter semester: ");
    scanf("%2s", subject->semester); 

    printf("Enter total subjects: ");
    scanf("%u", &subject->CountSubject);
}

// Input subject data
void getSubjectData(struct S *subject, int subjectCount) {
    for (int i = 0; i < subjectCount; i++) {
        printf("\nEnter CODE subject [%d]: ", i + 1);
        scanf("%s", subject->code[i]);  
        printf("Enter NAME subject : ");
        scanf("%s", subject->SubjectName[i]);  
        printf("Enter Credit subject : ");
        scanf("%d", &subject->Credit[i]);
        printf("Enter your SCORE subject : ");
        scanf("%d", &subject->point[i]);
    }
}

// Convert score to grade
const char* getGrade(int point) {
    if (point >= 80) return "A";
    else if (point >= 75) return "B+";
    else if (point >= 70) return "B";
    else if (point >= 65) return "C+";
    else if (point >= 60) return "C";
    else if (point >= 55) return "D+";
    else if (point >= 50) return "D";
    else return "F";
}

// Calculate GPA
void calculateGradeCredit(struct S *subject) {
    float totalWeighted = 0;
    int totalCredits = 0;

    for (int i = 0; i < subject->CountSubject; i++) {
        const char *grade = getGrade(subject->point[i]);
        float point = gradeToPoint(grade);
        totalWeighted += point * subject->Credit[i];
        totalCredits += subject->Credit[i];
    }

    float GPA = totalWeighted / totalCredits;
    printf("\nTotal your GPA : %.2f\n", GPA);
}

// Convert grade to point
float gradeToPoint(const char *grade) {
    if (strcmp(grade, "A") == 0) return 4.0;
    else if (strcmp(grade, "B+") == 0) return 3.5;
    else if (strcmp(grade, "B") == 0) return 3.0;
    else if (strcmp(grade, "C+") == 0) return 2.5;
    else if (strcmp(grade, "C") == 0) return 2.0;
    else if (strcmp(grade, "D+") == 0) return 1.5;
    else if (strcmp(grade, "D") == 0) return 1.0;
    else return 0; // F
}

// Calculate score and return to grade
void calculateAverageGrade(struct S *subject) {
    int totalPoints = 0;
    printf("\n");
    for (int i = 0; i < subject->CountSubject; i++) {
        totalPoints += subject->point[i];
        printf("Grade for subject %d (%s): %s\n", i + 1, subject->SubjectName[i], getGrade(subject->point[i]));
    }
}

// Show all subject info
void ShowData(struct S subject) {
    printf("\n\n====== Data Information =======\n");
    printf("NAME: %s\n", subject.name);
    printf("SEMESTER: %s\n", subject.semester);
    printf("TOTAL SUBJECTS: %u\n", subject.CountSubject);

    printf("\n===== Subject Information =====\n");
    for (int i = 0; i < subject.CountSubject; i++) {
        printf("\nSubject %d: %s\n", i + 1, subject.SubjectName[i]);
        printf("Code: %s\n", subject.code[i]);
        printf("Credit: %d\n", subject.Credit[i]);
        printf("Score: %d\n", subject.point[i]);
        printf("Grade: %s\n", getGrade(subject.point[i]));
    }
}