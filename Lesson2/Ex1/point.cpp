#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(int X, int Y):x(X), y(Y)
{ }
Point::Point(const Point& p)
{
   x=p.getX();
   y=p.getY();
}
void Point::print()
{
   cout<<'('<<x<<','<<y<<")\n";
}