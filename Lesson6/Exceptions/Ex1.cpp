#include<iostream>
using namespace std;

int ex1()
{
    int numerator = 10;
    int denominator = 0;
    int div = numerator / denominator;
    cout << "This text will not be printed.";
    return 0;
}

int ex2()
{
    try {
        throw 20;
    }
    catch (int e) {
        cout << "Exception # " << e << " occurred";
    }
    return 0;
}