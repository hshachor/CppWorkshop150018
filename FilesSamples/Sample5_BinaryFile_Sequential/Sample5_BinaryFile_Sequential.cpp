#include <iostream >
#include <fstream>
using namespace std;

//Binary File Sample 5

struct workers
{
	long id;
	char name[15];
	float hours;
	float salary;
};

int main()
{
	ofstream f1;
	f1.open("workers.txt");

	workers worker;

	for (int i = 0; i < 3; i++)
	{
		cout << "enter workers name ";
		cin >> worker.name;
		cout << "enter " << worker.name << "'s id ";
		cin >> worker.id;
		cout << "enter numbet of hours ";
		cin >> worker.hours;
		cout << "enter a salary per hour ";
		cin >> worker.salary;

		f1.write((char*)&worker, sizeof(workers));
	}

	f1.close();

	ifstream f2("workers.txt");
	f2.read((char *)&worker, sizeof(workers));
	while (!f2.eof())
	{
		cout << worker.name << worker.id << worker.hours << worker.salary << endl;
		f2.read((char *)&worker, sizeof(workers));
	}

	f2.close();

	return 0;
}
