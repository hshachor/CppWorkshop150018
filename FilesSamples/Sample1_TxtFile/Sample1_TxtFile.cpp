#include <iostream >
#include <fstream>
using namespace std;

//Text File Sample 1

int main()
{
	//fstream f0;

	
	
	char name[10];
	float grade;

	ifstream f1; //file for reading
	f1.open("students.txt");
	if (!f1)
	{
		cout << "File could not be opened.\n";
		return 0;
	}

	//ifstream f11 ("stt.txt");
	
	//ofstream f22( "fdfds");

	//open file for writing, 
	//if file not already exist, create new file
	ofstream f2; //file for writing
	f2.open("grades.txt");
	if (!f2)
	{
		cout << "File could not be opened.\n";
		return 0;
	}

	do
	{
		//read from file f1 using >> opertor
		//read until the first stopper (\n, \t, ' ')
		//read into 'name' 
		f1 >> name;

		cout << "enter " << name << "'s grade ";
		cin >> grade;

		//write 'name'into file f1 using << opertor
		f2 << name << '\t' << grade << endl;
	} while (!f1.eof());

	f1.close(); //don't forget to close
	f2.close(); //don't forget to close
	return 0;
}