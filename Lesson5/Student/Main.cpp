#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    char name[15];
    int mark;
    for (int i = 0; i < 10; i++)
    {
        cout << "enter students name and grade\n";
        cin >> name >> mark;
        Student s(name);
        s.setGrade(mark);
        s.percentageOfFailers();
    }

    //cout << Student::numOfStudents;  // error. numOfStudents and numOfFails are private
    //cout << Student::numOfFails; 
    return 0;
}
