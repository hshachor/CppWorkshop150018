#include <iostream >
#include <fstream>
using namespace std;

struct workers
{
    long id; // integer 4-bytes (32-bit) // int is spec depended (2/4 bytes).
    char name[15];
    float hours;
    float salary;
};

int main()
{
    ofstream f1;
    f1.open("workers.txt");
    if (!f1) {
        std::cout << "error open file\n";
        return 0;
    }
    workers worker;

    for (int i = 0; i < 3; i++) {
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
    f2.read((char*)&worker, sizeof(workers));
    while (!f2.eof()) {
        cout << worker.name << endl;
        f2.read((char*)&worker, sizeof(workers));
    }
    return 0;
}