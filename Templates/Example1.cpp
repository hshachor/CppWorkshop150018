#include <iostream>

using namespace std;

int max(int x, int y)
{
    if (x > y)
        return x;
    return y;
}

float max(float x, float y)
{
    if (x > y)
        return x;
    return y;
}

char max(char x, char y)
{
    if (x > y)
        return x;
    return y;
}

int main()
{
    cout << max(3, 4) << endl;

    float a = 5.25, b = 3.5;
    cout << max(a, b) << endl;

    cout << max('a', 'z') << endl;

    return 0;
}