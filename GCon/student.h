#ifndef STUDENT_H
#define STUDENT_H


struct student {
    int studentID;
    double percentMark;
};

int compare_students_by_id(const void *a, const void *b);
int compare_students_by_percent(const void *a, const void *b);

#endif /* STUDENT_H */
