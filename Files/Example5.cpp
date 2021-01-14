#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char line[150];
    int i = 1;
    ifstream txt;

    txt.open("text.txt");
    txt.getline(line, 150, '\n');
    while (!txt.eof()) {
        cout << i << ":\t" << line << endl;
        txt.getline(line, 150);
        i++;
    }

    return 0;
}