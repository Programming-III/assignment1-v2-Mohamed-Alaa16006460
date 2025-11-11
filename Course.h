#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Student.h"
#include "Instructor.h"
using namespace std;

class Course {
private:
    string courseCode;
    string courseName;
    int maxStudents;
    Student* students;
    int currentStudents;
    Instructor instructor;

public:
    Course();
    Course(string code, string name, int max, const Instructor& inst);
    ~Course();

    void addStudent(const Student& s);
    void displayCourseInfo() const;
};

#endif

