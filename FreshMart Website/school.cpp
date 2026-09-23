#include <stdio.h>
#include <string.h>

#define MAX 100

// ---------- Structures ----------
struct Student {
    int roll;
    char name[50];
    char className[10];
    float fees;
};

struct Teacher {
    int id;
    char name[50];
    char subject[30];
};

// ---------- Global Arrays ----------
struct Student students[MAX];
struct Teacher teachers[MAX];

int studentCount = 0;
int teacherCount = 0;

// ---------- Function Declarations ----------
void addStudent();
void viewStudents();
void searchStudent();
void addTeacher();
void viewTeachers();
void mainMenu();

// ---------- Main Function ----------
int main() {
    mainMenu();
    return 0;
}

// ---------- Main Menu ----------
void mainMenu() {
    int choice;
    do {
        printf("\n==============================");
        printf("\n  SCHOOL MANAGEMENT SYSTEM");
        printf("\n==============================");
        printf("\n1. Add Student");
        printf("\n2. View Students");
        printf("\n3. Search Student");
        printf("\n4. Add Teacher");
        printf("\n5. View Teachers");
        printf("\n0. Exit");
        printf("\n------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: addTeacher(); break;
            case 5: viewTeachers(); break;
            case 0: printf("\nExiting program...\n"); break;
            default: printf("\nInvalid choice!\n");
        }
    } while (choice != 0);
}

// ---------- Student Functions ----------
void addStudent() {
    if (studentCount >= MAX) {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter Roll No: ");
    scanf("%d", &students[studentCount].roll);
    getchar();

    printf("Enter Name: ");
    fgets(students[studentCount].name, 50, stdin);
    students[studentCount].name[strcspn(students[studentCount].name, "\n")] = 0;

    printf("Enter Class: ");
    scanf("%s", students[studentCount].className);

    printf("Enter Fees: ");
    scanf("%f", &students[studentCount].fees);

    studentCount++;
    printf("\nStudent added successfully!\n");
}

void viewStudents() {
    if (studentCount == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n----- Student List -----\n");
    for (int i = 0; i < studentCount; i++) {
        printf("\nRoll No : %d", students[i].roll);
        printf("\nName    : %s", students[i].name);
        printf("\nClass   : %s", students[i].className);
        printf("\nFees    : %.2f", students[i].fees);
        printf("\n-----------------------");
    }
}

void searchStudent() {
    int roll, found = 0;

    printf("\nEnter Roll No to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].roll == roll) {
            printf("\nStudent Found!");
            printf("\nName  : %s", students[i].name);
            printf("\nClass : %s", students[i].className);
            printf("\nFees  : %.2f", students[i].fees);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent not found!");
}

// ---------- Teacher Functions ----------
void addTeacher() {
    if (teacherCount >= MAX) {
        printf("\nTeacher limit reached!\n");
        return;
    }

    printf("\nEnter Teacher ID: ");
    scanf("%d", &teachers[teacherCount].id);
    getchar();

    printf("Enter Name: ");
    fgets(teachers[teacherCount].name, 50, stdin);
    teachers[teacherCount].name[strcspn(teachers[teacherCount].name, "\n")] = 0;

    printf("Enter Subject: ");
    fgets(teachers[teacherCount].subject, 30, stdin);
    teachers[teacherCount].subject[strcspn(teachers[teacherCount].subject, "\n")] = 0;

    teacherCount++;
    printf("\nTeacher added successfully!\n");
}

void viewTeachers() {
    if (teacherCount == 0) {
        printf("\nNo teacher records available.\n");
        return;
    }

    printf("\n----- Teacher List -----\n");
    for (int i = 0; i < teacherCount; i++) {
        printf("\nID      : %d", teachers[i].id);
        printf("\nName    : %s", teachers[i].name);
        printf("\nSubject : %s", teachers[i].subject);
        printf("\n-----------------------");
    }
}
