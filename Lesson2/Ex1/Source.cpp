#include "point.h"
#include <iostream>
using namespace std;


void main()
{
   point p1,
            p2(2,8),
            p3(p2);
   cout<<"p1: ";	p1.print();
   cout<<"p2: ";	p2.print();
   cout<<"p3: ";    p3.print();
}
