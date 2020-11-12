
#include "List.h"
#include <iostream>
using namespace std;


int main()
{
    int element;
    List ls1, ls2;
    try
    {
        for (int i = 0; i < 5; i++)
        {
            ls1.add(i);
            //cout << i << " ";
        }
        cout << ls1;
        ////ls1.removeFirst();
        for (int i = 0; i < 5; i++)
        {
            element = ls1.firstElement();
            ls1.removeFirst();
            //cout << element << " ";
            ls2.add(element);
        }
        cout << "ls1: " << ls1;
        cout << "ls2:" << ls2;

        cout << endl;
        cout << ((ls2.search(4)) ? "ls2 includes 4" :
            "ls2 doesn't include 4") << endl;
        cout << ((ls2.search(3)) ? "ls2 includes 3" :
            "ls2 doesn't include 3") << endl;
        ls2.removeFirst();
        cout << ((ls2.search(3)) ? "ls2 includes 3" :
            "ls2 doesn't include 3") << endl;
    }
    catch (const char* problem)
    {
        cout << problem;
    }

    return 0;
}

