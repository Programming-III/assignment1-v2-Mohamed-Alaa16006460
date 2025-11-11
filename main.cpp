#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Instructor.h"
#include "Course.h"

using namespace std;

// ==================== Person Class Implementation =========================
Person::Person() {
    name = "";
    id = 0;
}

Person::Person(string n, int i) {
    name = n;
    id = i;
}

Person::~Person() {}

void Person::setName(string n) { name = n; }
void Person::setId(int i) { id = i; }

string Person::getName() const { return name; }
int Person::getId() const { return id; }

void Person::display() const {
    cout << "Name: " << name << " (ID: " << id << ")" << endl;
}

// ==================== Student Class Implementation ====================
Student::Student() : Person() {
    yearLevel = 0;
    major = "";
}

Student::Student(string n, int i, int y, string m) : Person(n, i) {
    yearLevel = y;
    major = m;
}

Student::~Student() {}

void Student::setYearLevel(int y) { yearLevel = y; }
void Student::setMajor(string m) { major = m; }

int Student::getYearLevel() const { return yearLevel; }
string Student::getMajor() const { return major; }

void Student::display() const {
    cout << "Name: " << getName() << endl;
    cout << "Year: " << yearLevel << endl;
    cout << "Major: " << major << endl;
}

// ==================== Instructor Class Implementation ====================
Instructor::Instructor() : Person() {
    department = "";
    experienceYears = 0;
}

Instructor::Instructor(string n, int i, string d, int e) : Person(n, i) {
    department = d;
    experienceYears = e;
}

Instructor::~Instructor() {}

void Instructor::setDepartment(string d) { department = d; }
void Instructor::setExperienceYears(int e) { experienceYears = e; }

string Instructor::getDepartment() const { return department; }
int Instructor::getExperienceYears() const { return experienceYears; }

void Instructor::display() const {
    cout << "Name: " << getName() << endl;
    cout << "Department: " << department << endl;
    cout << "Experience: " << experienceYears << " years" << endl;
}

// ==================== Course Class Implementation ====================
Course::Course() {
    courseCode = "";
    courseName = "";
    maxStudents = 0;
    currentStudents = 0;
    students = nullptr;
}

Course::Course(string code, string name, int max, const Instructor& inst) {
    courseCode = code;
    courseName = name;
    maxStudents = max;
    currentStudents = 0;
    instructor = inst;
    students = new Student[maxStudents];
}

Course::~Course() {
    delete[] students;
}

void Course::addStudent(const Student& s) {
    if (currentStudents < maxStudents) {
        students[currentStudents] = s;
        currentStudents++;
    } else {
        cout << "Course is full. Cannot add more students.\n";
    }
}

void Course::displayCourseInfo() const {
    cout << "Course: " << courseCode << " - " << courseName << endl;
    cout << "Max Students: " << maxStudents << endl;
    cout << "Currently Enrolled: ";
    if (currentStudents > 0) {
        cout << students[0].getName() << " (ID: " << students[0].getId() << ")";
    }
    cout << endl << endl;

    cout << "Instructor Info:" << endl;
    instructor.display();
    cout << endl;

    cout << "Student Info:" << endl;
    for (int i = 0; i < currentStudents; i++) {
        students[i].display();
        cout << endl;
    }
}

// ==================== Main Function ====================
int main() {
    Instructor inst("Dr. Lina Khaled", 1001, "Computer Science", 5);
    Student s1("Omar Nabil", 2202, 2, "Informatics");
    Course course("CS101", "Introduction to Programming", 3, inst);
    course.addStudent(s1);
    course.displayCourseInfo();
    return 0;
}
