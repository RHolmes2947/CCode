#ifndef StuRes_H
#define StuRes_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 100
#define MAX_ID_LENGTH 6
#define MAX_COURSE_CODE_LENGTH 8

void promptStudents(int *numStudents, int **studentIDs);
void promptCourses(int *numCourses, char ***courseCodes);
void displayMenu();
void registerStudent(int numStudents, int numCourses, int *studentIDs, char **courseCodes, char **registrationTable);
void dropStudent(int numStudents, int numCourses, int *studentIDs, char **courseCodes, char **registrationTable);
void displayRegistrationTable(int numStudents, int numCourses, int *studentIDs, char **courseCodes, char **registrationTable);
int findStudentIndex(int numStudents, int *studentIDs, int studentID);
int findCourseIndex(int numCourses, char **courseCodes, char *courseCode);
bool validateStudentID(int studentID);
bool validateCourseCode(char *courseCode);
void clearInputBuffer();
void freeMemory(int numStudents, int *studentIDs, int numCourses, char **courseCodes, char **registrationTable);

#endif /* StuRes_H */
