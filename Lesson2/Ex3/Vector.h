#pragma once
//Example Channi Nadler
class Vector
{
private:
   int *numbers;
   int size;
public:
   Vector(int Size = 10);
   Vector(int val, int Size);
   Vector( int* vec,int Size=10);
   Vector(const Vector& vec);
   ~Vector();
   void print();
};