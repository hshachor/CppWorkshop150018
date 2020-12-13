#include <iostream>
#include <vector>

using namespace std;

void display(const char* vecName, vector<int> vec)
{
    cout << vecName << ": ";
    for (auto it = vec.begin(); it != vec.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
}

int main()
{
    vector<int> v1;            // empty vector of ints
    vector<int> v2(4, 100);    // four ints with value 100
    vector<int> v3(v2.begin(), v2.end());
    // iterating through second
 
    int myints[] = { 16,2,77,29 };
    vector<int> v4(myints, myints + 4);
    
    display("v1", v1);
    display("v2", v2);
    display("v3", v3);
    display("v4", v4);
    
    return 0;
}