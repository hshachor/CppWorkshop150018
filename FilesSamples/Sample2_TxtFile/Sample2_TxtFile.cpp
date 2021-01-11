#include <iostream>
#include <fstream>
#include<string>
using namespace std;

//Text File Sample 2

int main()
{
	string fname, lname;
	int age;
	ifstream in("kelet.txt");

	if (!in)
	{
		cout << "could not open file.\n";
		return 0;
	}

	
	while (!in.eof())
	{
		in >> fname >> lname >> age;
		cout << fname << ' ' << lname;
		if (age >20)
			cout << "can work" << '\n';
		else
			cout << "can’t work" << '\n';
	}
	return 0;
}