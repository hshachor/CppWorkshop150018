#include <iostream >
#include <fstream>
#include <string>

using namespace std;

//Text File Sample 3

int main()
{
	char myline[150];
	int i = 1;
	string stline;

	ifstream txt;
	txt.open("text.txt");

	//read from file txt using getline function
	//read until the end of line (\n)
	//read 150 chars into 'myline' 
	txt.getline(myline, 150);
	//txt.getline((char*)stline.c_str(), 150);

	while (!txt.eof())
	{
		cout << i << ":\t" << myline << endl;
		txt.getline(myline, 150);
		i++;
	}
	return 0;
}
