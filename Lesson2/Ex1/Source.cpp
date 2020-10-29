#include "Point.h"
#include <iostream>
using namespace std;
#if 1


void main()
{
   Point p1,
            p2(2,8),
            p3(p2);
   cout<<"p1: ";	p1.print();
   cout<<"p2: ";	p2.print();
   cout<<"p3: ";    p3.print();
}










#else
class Myclass {
    int x;
public:
    Myclass() :x(0) { cout << "object constructed\n"; }
    ~Myclass() { cout << "object destructed\n"; }
};

void fun(Myclass temp) { }

void main() {
    Myclass a;
    fun(a);
}

#endif 