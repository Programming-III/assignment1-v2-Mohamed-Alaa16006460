#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>
using namespace std;

class Student : public Person {
private:
    int yearLevel;
    string major;

public:
    Student();
    Student(string n, int i, int y, string m);
    ~Student();

    void setYearLevel(int y);
    void setMajor(string m);

    int getYearLevel() const;
    string getMajor() const;

    void display() const;
};

#endif
