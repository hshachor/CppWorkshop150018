#include <iostream>
#include "Vector.h"
#include <ctime>
using namespace std;

Vector::Vector(int _size)
{
    size = _size;
    numbers = new int[size];
    srand((unsigned)time(NULL));
    for (int i = 0; i < size; i++)
        numbers[i] = rand() % 100;
    cout << "ctor random\n";
}

Vector::Vector(int val, int _size)
{
    size = _size;
    numbers = new int[size];
    for (int i = 0; i < size; i++)
        numbers[i] = val;
    cout << "ctor value\n";
}

Vector::Vector(int* vec, int _size)
{
    size = _size;
    numbers = new int[size];
    for (int i = 0; i < size; i++)
        numbers[i] = vec[i];
    cout << "ctor array\n";
}

Vector::~Vector()
{
    cout << " dtor" << endl;
    if (size) {
        delete[] numbers;
    }
}

Vector::Vector(const Vector& vec)
{
    size = vec.size;
    numbers = new int[size];
    for (int i = 0; i < size; i++)
        numbers[i] = vec.numbers[i];
    cout << "copy ctor\n";
}

void Vector::print()
{
    for (int i = 0; i < size; i++)
        cout << numbers[i] << ' ';
    cout << endl;
}