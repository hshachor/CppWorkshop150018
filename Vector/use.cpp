#include "Vector.h"
#include <iostream>

using namespace std;

int main()
{
    Vector <int> nums; 
    Vector <float> rels; 
    nums.insert(58); 
    nums.insert(42); 
    rels.insert((float)58 / 100); 
    rels.insert((float)42 / 100); 
    for (int index = 0; index < nums.getSize(); index++)
        cout << nums[index] << "  "; 
    cout << endl; 
    for (int index = 0; index < rels.getSize(); index++)
        cout << rels[index] << "  "; 
    return 0; 
}
/*
Output:
58 42
0.58 0.42
*/