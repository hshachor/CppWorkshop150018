#pragma once
//Example Channi Nadler
class Point
{
private:
   int x = 0;
   int y;
public:
   //default constructor
   Point() {y=0;}
   Point(int, int);
   //copy constructor
   Point(const Point& p);
   int getX() const{return x;}
   int getY() const{return y;}
   void print();
};