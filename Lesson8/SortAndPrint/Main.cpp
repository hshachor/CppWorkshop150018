#include <iostream>
#include "Numbers.h"
#include "Strings.h"

using namespace std;

int main()
{
    Numbers nums(5);
    cout << "Print Before Sort:\n";
    nums.print();
    nums.bubbleSort();
    cout << "Print After Sort:\n";
    nums.print();

    Strings words("Sara", "Rivka", "Rachel", "Leah");
    cout << "Print Before Sort:\n";
    words.print();
    words.bubbleSort();
    cout << "Print After Sort:\n";
    words.print();
    return 0;
}

