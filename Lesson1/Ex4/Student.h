#pragma once
class Student
{
//private:
#if 0
	string name;
#else
	char name[20];
#endif
	int grade;
	int marks[10];
	float average;

	int sum();

public:
	void setGrade();
	int getGrade();
	void setMarks();
	void setAverage();
	float getAverage();

};

