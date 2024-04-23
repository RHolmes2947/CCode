#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "StuRes.h"

#define MAX_STUDENTS 100
#define MAX_COURSES 100
#define MAX_ID_LENGTH 6
#define MAX_COURSE_CODE_LENGTH 8

// Function prototypes
void promptStudents(int *numStudents, int **studentIDs);
// Function Name: promptStudents
// Purpose: Prompts the user to enter the number of students and their IDs.
// Function in parameters: Pointer to the variable storing the number of students, pointer to the array storing student IDs
// Function out parameter: None

void promptCourses(int *numCourses, char ***courseCodes);
// Function Name: promptCourses
// Purpose: Prompts the user to enter the number of courses and their codes.
// Function in parameters: Pointer to the variable storing the number of courses, pointer to the array storing course codes
// Function out parameter: None

void displayMenu();
// Function Name: displayMenu
// Purpose: Displays the menu options to the user.
// Function in parameters: None
// Function out parameter: None

void registerStudent(int numStudents, int numCourses, int *studentIDs, char **courseCodes, char **registrationTable);
// Function Name: registerStudent
// Purpose: Registers a student into a course.
// Function in parameters: Number of students, number of courses, array of student IDs, array of course codes, registration table
// Function out parameter: None

void dropStudent(int numStudents, int numCourses, int *studentIDs, char **courseCodes, char **registrationTable);
// Function Name: dropStudent
// Purpose: Drops a student from a course.
// Function in parameters: Number of students, number of courses, array of student IDs, array of course codes, registration table
// Function out parameter: None

void displayRegistrationTable(int numStudents, int numCourses, int *studentIDs, char **courseCodes, char **registrationTable);
// Function Name: displayRegistrationTable
// Purpose: Displays the registration table with student registrations.
// Function in parameters: Number of students, number of courses, array of student IDs, array of course codes, registration table
// Function out parameter: None

int findStudentIndex(int numStudents, int *studentIDs, int studentID);
// Function Name: findStudentIndex
// Purpose: Finds the index of a student ID in the array of student IDs.
// Function in parameters: Number of students, array of student IDs, student ID to search for
// Function out parameter: Index of the student ID if found, -1 if not found

int findCourseIndex(int numCourses, char **courseCodes, char *courseCode);
// Function Name: findCourseIndex
// Purpose: Finds the index of a course code in the array of course codes.
// Function in parameters: Number of courses, array of course codes, course code to search for
// Function out parameter: Index of the course code if found, -1 if not found

bool validateStudentID(int studentID);
// Function Name: validateStudentID
// Purpose: Validates the format of a student ID.
// Function in parameters: Student ID to validate
// Function out parameter: True if the student ID is valid, false otherwise

bool validateCourseCode(char *courseCode);
// Function Name: validateCourseCode
// Purpose: Validates the format of a course code.
// Function in parameters: Course code to validate
// Function out parameter: True if the course code is valid, false otherwise

void clearInputBuffer();
// Function Name: clearInputBuffer
// Purpose: Clears the input buffer.
// Function in parameters: None
// Function out parameter: None

void freeMemory(int numStudents, int *studentIDs, int numCourses, char **courseCodes, char **registrationTable);
// Function Name: freeMemory
// Purpose: Frees the memory allocated for arrays.
// Function in parameters: Number of students, array of student IDs, number of courses, array of course codes, registration table
// Function out parameter: None

int main() {
    int numStudents, numCourses;
    int *studentIDs = NULL;
    char **courseCodes = NULL;
    char **registrationTable = NULL;

    promptStudents(&numStudents, &studentIDs);
    promptCourses(&numCourses, &courseCodes);

    registrationTable = (char **)malloc(numStudents * sizeof(char *));
    for (int i = 0; i < numStudents; i++) {
        registrationTable[i] = (char *)malloc(MAX_COURSES * sizeof(char));
        memset(registrationTable[i], ' ', MAX_COURSES * sizeof(char));
    }

    while (true) {
        displayMenu();
        int choice;
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }

        switch (choice) {
            case 1:
                registerStudent(numStudents, numCourses, studentIDs, courseCodes, registrationTable);
                break;
            case 2:
                dropStudent(numStudents, numCourses, studentIDs, courseCodes, registrationTable);
                break;
            case 3:
                displayRegistrationTable(numStudents, numCourses, studentIDs, courseCodes, registrationTable);
                break;
            case 4:
                printf("Exiting the program.\n");
                freeMemory(numStudents, studentIDs, numCourses, courseCodes, registrationTable);
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void promptStudents(int *numStudents, int **studentIDs) {
    printf("Enter the number of students to register: ");
    while (scanf("%d", numStudents) != 1 || *numStudents < 1 || *numStudents > MAX_STUDENTS) {
        printf("Invalid number of students. Enter a valid number: ");
        clearInputBuffer();
    }

    *studentIDs = (int *)malloc(*numStudents * sizeof(int));

    printf("Enter the student IDs:\n");
    for (int i = 0; i < *numStudents; i++) {
        printf("Student %d ID: ", i + 1);
        while (scanf("%d", &((*studentIDs)[i])) != 1 || !validateStudentID((*studentIDs)[i])) {
            printf("Student ID must be 5 digits: ");
            clearInputBuffer();
        }
    }
}

void promptCourses(int *numCourses, char ***courseCodes) {
    printf("Enter the number of courses offered: ");
    while (scanf("%d", numCourses) != 1 || *numCourses < 1 || *numCourses > MAX_COURSES) {
        printf("Invalid number of courses. Enter a valid number: ");
        clearInputBuffer();
    }

    *courseCodes = (char **)malloc(*numCourses * sizeof(char *));
    for (int i = 0; i < *numCourses; i++) {
        (*courseCodes)[i] = (char *)malloc(MAX_COURSE_CODE_LENGTH * sizeof(char));
    }

    printf("Enter the course codes:\n");
    for (int i = 0; i < *numCourses; i++) {
        printf("Course %d code: ", i + 1);
        while (scanf("%s", (*courseCodes)[i]) != 1 || !validateCourseCode((*courseCodes)[i])) {
            printf("Invalid course code format[3-Alphas][4-digits]. Enter a valid code: ");
            clearInputBuffer();
        }
    }
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Register a student into a course\n");
    printf("2. Drop a student from a course\n");
    printf("3. Display the registration table\n");
    printf("4. Quit the program\n");
}

void registerStudent(int numStudents, int numCourses, int *studentIDs, char **courseCodes, char **registrationTable) {
    int studentID;
    char courseCode[MAX_COURSE_CODE_LENGTH];

    printf("List of student IDs:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("index %-10d %d\n", i, studentIDs[i]);
    }
    printf("\n");

    printf("Enter the student ID: ");
    while (scanf("%d", &studentID) != 1 || !validateStudentID(studentID)) {
        printf("Invalid student ID. Enter a valid ID: ");
        clearInputBuffer();
    }

    int studentIndex = findStudentIndex(numStudents, studentIDs, studentID);
    if (studentIndex == -1) {
        printf("Student ID not found. Try again.\n");
        return;
    }

    printf("List of course codes:\n");
    for (int i = 0; i < numCourses; i++) {
        printf("index %-10d %s\n", i, courseCodes[i]);
    }
    printf("\n");

    printf("Enter the course code: ");
    while (scanf("%s", courseCode) != 1 || !validateCourseCode(courseCode)) {
        printf("Invalid course code[3-Alphas][4-digits]. Enter a valid code: ");
        clearInputBuffer();
    }

    int courseIndex = findCourseIndex(numCourses, courseCodes, courseCode);
    if (courseIndex == -1) {
        printf("Course code not found. Try again.\n");
        return;
    }

   
    if (registrationTable[studentIndex][courseIndex] == 'D') {
        printf("Student with ID %d has dropped out of the course with code %s. Cannot re-enroll.\n", studentID, courseCode);
        return;
    }

    
    if (registrationTable[studentIndex][courseIndex] == 'R') {
        printf("Student with ID %d is already registered in the course with code %s.\n", studentID, courseCode);
        return;
    }

    registrationTable[studentIndex][courseIndex] = 'R';
    printf("Student with ID %d registered in the course with code %s.\n", studentID, courseCode);
}




void dropStudent(int numStudents, int numCourses, int *studentIDs, char **courseCodes, char **registrationTable) {
    displayRegistrationTable(numStudents, numCourses, studentIDs, courseCodes, registrationTable);

    printf("Please select the index number of the registration to drop: ");
    int registrationIndex;
    while (scanf("%d", &registrationIndex) != 1 || registrationIndex < 0 || registrationIndex >= numStudents * numCourses) {
        printf("Invalid index. Please enter a valid registration index number: ");
        clearInputBuffer();
    }

    int studentIndex = registrationIndex / numCourses;
    int courseIndex = registrationIndex % numCourses;

    if (registrationTable[studentIndex][courseIndex] == 'R') {
        registrationTable[studentIndex][courseIndex] = 'D';
        printf("Student with ID %d dropped from the selected course.\n", studentIDs[studentIndex]);
    } else {
        printf("No student registered at the selected index.\n");
    }
}







void displayRegistrationTable(int numStudents, int numCourses, int *studentIDs, char **courseCodes, char **registrationTable) {
    printf("\nRegistration Table:\n\n");

    printf("%-20s %-20s %-20s %-20s\n", "Registration index", "Student ID", "Course ID", "Registration status");

    int index = 0;
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numCourses; j++) {
            if (registrationTable[i][j] == 'R' || registrationTable[i][j] == 'D') {
                printf("%-20d %-20d %-20s %-20c\n", index, studentIDs[i], courseCodes[j], registrationTable[i][j]);
                index++;
            }
        }
    }
}

int findStudentIndex(int numStudents, int *studentIDs, int studentID) {
    for (int i = 0; i < numStudents; i++) {
        if (studentIDs[i] == studentID) {
            return i;
        }
    }
    return -1;
}

int findCourseIndex(int numCourses, char **courseCodes, char *courseCode) {
    for (int i = 0; i < numCourses; i++) {
        if (strcmp(courseCodes[i], courseCode) == 0) {
            return i;
        }
    }
    return -1;
}

bool validateStudentID(int studentID) {
    if (studentID >= 10000 && studentID <= 99999) {
        return true;
    }
    return false;
}

bool validateCourseCode(char *courseCode) {
    if (strlen(courseCode) != MAX_COURSE_CODE_LENGTH - 1) {
        return false;
    }

    for (int i = 0; i < 3; i++) {
        if (!isalpha(courseCode[i])) {
            return false;
        }
    }

    for (int i = 3; i < MAX_COURSE_CODE_LENGTH - 1; i++) {
        if (!isdigit(courseCode[i])) {
            return false;
        }
    }

    return true;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void freeMemory(int numStudents, int *studentIDs, int numCourses, char **courseCodes, char **registrationTable) {
    free(studentIDs);
    for (int i = 0; i < numCourses; i++) {
        free(courseCodes[i]);
    }
    free(courseCodes);
    for (int i = 0; i < numStudents; i++) {
        free(registrationTable[i]);
    }
    free(registrationTable);
}