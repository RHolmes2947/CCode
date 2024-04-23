#include "student.h"


int compare_students_by_id(const void *a, const void *b) {
    struct student *s1 = (struct student *)a;
    struct student *s2 = (struct student *)b;
    return s1->studentID - s2->studentID;
}

int compare_students_by_percent(const void *a, const void *b) {
    struct student *s1 = (struct student *)a;
    struct student *s2 = (struct student *)b;
    return (s1->percentMark > s2->percentMark) - (s1->percentMark < s2->percentMark);
}
