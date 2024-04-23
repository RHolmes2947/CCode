#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "grade_converter.h"




int main(int argc, char *argv[]) {
    int i;
    char *filename;
    FILE *file;
    long file_size;
    int num_students;
    double sum = 0.0;
    double average;
    double median;
    struct student *students; 

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Unable to open file '%s'\n", filename);
        return 1;
    }

    /* Get the number of students in the file */
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    num_students = file_size / sizeof(struct student);
    fseek(file, 0, SEEK_SET);

    /* Allocate memory for students */
    students = (struct student *)malloc(num_students * sizeof(struct student));

    /* Read the students from the file */
    fread(students, sizeof(struct student), num_students, file);
    fclose(file);

    /* Sort the data in ascending order using the student identifier */
    qsort(students, num_students, sizeof(struct student), compare_students_by_id);

    /* Print out the sorted student data with letter grades */
    printf("%-15s%-15s%-15s\n", "Student ID", "Percentage", "Letter Grade");
    for (i = 0; i < num_students; i++) {
        printf("%-15d%-15.2f%-15s\n", students[i].studentID, students[i].percentMark, get_letter_grade(students[i].percentMark));
    }

    /* Calculate the average and median numeric grade */
    for (i = 0; i < num_students; i++) {
        sum += students[i].percentMark;
    }
    average = sum / num_students;

    qsort(students, num_students, sizeof(struct student), compare_students_by_percent);

    if (num_students % 2 == 0) {
        median = (students[num_students / 2 - 1].percentMark + students[num_students / 2].percentMark) / 2.0;
    } else {
        median = students[num_students / 2].percentMark;
    }

    /* Printing the average and median numeric grade */
    printf("\nAverage Numeric Grade: %.2f\n", average);
    printf("Median Numeric Grade: %.2f\n", median);

    free(students);

    return 0;
}
