#include <iostream >
#include <fstream>
using namespace std;


//Text File Sample 4

int main()
{
	int line = 0, words = 0, chars = 0;

	ifstream txt;
	txt.open("students.txt");

	//read from file txt using get function
	//read only one char
	char c = txt.get();
	char tav = ' ';

	while (!txt.eof())
	{
		if (c != ' ' && c != '\t' && c != '\n') chars++;
		if (c == ' ' && c == '\t' && c == '\n' && tav != ' ' && tav != '\t' && tav != '\n') words++;
		if (c == '\n' && tav != '\n')
		{
			line++;
			words++;
		}

		tav = c;
		c = txt.get();
	}

	cout << "# of characters: " << chars << endl;
	cout << "# of words: " << words << endl;
	cout << "# of lines: " << line << endl;

	return 0;
}
