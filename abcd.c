#include <stdio.h>
#include <stdlib.h>  
#include <string.h>

#define MAX_STUDENTS 60
#define MAX_SUBJECTS 7
#define MAX_NAME_LENGTH 30

typedef struct {
    char name[MAX_NAME_LENGTH];
    int scores[MAX_SUBJECTS];   
    int numSubjects;
    float averageScore;
    int highestScore;
    int lowestScore;
} Student;

void calculateScores(Student *student) {
    int sum = 0;
    student->highestScore = student->scores[0];
    student->lowestScore = student->scores[0];
    
    for (int i = 0; i < student->numSubjects; i++) {
        sum += student->scores[i];
        if (student->scores[i] > student->highestScore) {
            student->highestScore = student->scores[i];
        }
        if (student->scores[i] < student->lowestScore) {
            student->lowestScore = student->scores[i];
        }
    }
    
    student->averageScore = (float)sum / student->numSubjects;
}

void displaySummary(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student Full Name: %s\n", students[i].name);
        printf("Average Score Of All Subjects: %.2f\n", students[i].averageScore);
        printf("Highest Score: %d\n", students[i].highestScore);
        printf("Lowest Score: %d\n", students[i].lowestScore);
        printf("----------------------------------------\n");
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int numStudents;
    
    printf("Enter Number Of Students: ");
    scanf("%d", &numStudents);
    getchar(); 

    for (int i = 0; i < numStudents; i++) {
        printf("Enter Name Of Student %d: ", i + 1);
        fgets(students[i].name, MAX_NAME_LENGTH, stdin);
        students[i].name[strcspn(students[i].name, "\n")] = 0; 
        
        printf("Enter Number Of Subjects For %s: ", students[i].name);
        scanf("%d", &students[i].numSubjects);

        for (int j = 0; j < students[i].numSubjects; j++) {
            printf("Enter Score For Subject %d: ", j + 1);
            scanf("%d", &students[i].scores[j]);
        }
        getchar(); 

        calculateScores(&students[i]);
    }

    displaySummary(students, numStudents);

    return 0;
}