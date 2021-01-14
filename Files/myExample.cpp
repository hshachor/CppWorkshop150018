#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char SPACE = ' ';
const char NEWLINE = '\n';
struct workers
{
    long id;
    char name[15];
    float hours;
    float salary;
};
int main()
{
    workers worker;
    ifstream f2("workers.txt");
    if (!f2) {
        cout << "could not open the file\n";
        return 0;
    }
    cout << "which worker do you want to read?";
    int i;
    cin >> i;
    f2.seekg((i-1) * sizeof(worker));
    f2.read((char*)&worker, sizeof(workers));
    cout << worker.name;
    
}
