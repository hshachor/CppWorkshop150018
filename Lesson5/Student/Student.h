#pragma once
using namespace std;

class Student
{
private:
    char name[20];
    int grade;
    static int numOfStudents;
    static int numOfFails;
public:
    Student(char* n);
    void setGrade(int g);
    void percentageOfFailers();
};

