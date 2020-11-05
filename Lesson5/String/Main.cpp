#include <iostream>
#include "String.h"

using std::cout;
using std::endl;

void main()
{
    String s1("Hello");
    String s2("people");
    String s3 = s1 + s2;
    if (s1 == s2)
        cout << "equal" << endl;
    s1.print();
    cout << " ";
    s2.print();
    cout << endl;
}
