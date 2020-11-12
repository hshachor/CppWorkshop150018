#include "Student.h"
#include <cstring>
#include <iostream>

using std::cout;

int Student::numOfStudents = 0;
int Student::numOfFails = 0;

Student::Student(char* n)
{
    strcpy_s(name, n);
    numOfStudents++;
}
void Student::setGrade(int g)
{
    grade = g;
    cout << grade << endl;
    if (grade < 55)
        numOfFails++;
}
void Student::percentageOfFailers()
{
    cout << (float)numOfFails / numOfStudents * 100;
    cout << "% of the students failed\n";
}
