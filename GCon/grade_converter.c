#include "grade_converter.h"

const char* get_letter_grade(double percentMark) {
    if (percentMark >= 90) return "A+";
    else if (percentMark >= 85) return "A";
    else if (percentMark >= 80) return "A-";
    else if (percentMark >= 77) return "B+";
    else if (percentMark >= 73) return "B";
    else if (percentMark >= 70) return "B-";
    else if (percentMark >= 67) return "C+";
    else if (percentMark >= 63) return "C";
    else if (percentMark >= 60) return "C-";
    else if (percentMark >= 57) return "D+";
    else if (percentMark >= 53) return "D";
    else if (percentMark >= 50) return "D-";
    else return "F";
}
