#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int main()
{
    string fname, lname;
    int age;

    ifstream in("kelet.txt");
    if (!in) {
        cout << "could not open file.\n";
        return 0;
    }

    while (in >> fname >> lname >> age) {
        cout << fname << ' ' << lname << '\n';
        if (age > 20)
            cout << "can work";
        else
            cout << "can't work";
    }
    return 0;
}