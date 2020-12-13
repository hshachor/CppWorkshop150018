#include <iostream> 
using namespace std;

template <class T>
T getMax(T x, T y)
{
    if (x > y)
        return x;
    return y;
}

int main()
{
    cout << getMax<int>(3, 4) << endl;

    float a = 5.25, b = 3.5;
    cout << getMax<float>(a, b) << endl;

    cout << getMax<char>('a', 'z') << endl;

    return 0;
}