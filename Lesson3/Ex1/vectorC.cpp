
#include <iostream>
#include "vectorC.h"
using namespace std;

vector::vector()
{
   cout<<"enter 10 numbers\n";
   for (int i=0;i<10;i++)
      cin>>numbers[i];
}
int vector::add()
{
   int sum=0;
   for (int i=0;i<10;i++)
      sum+=numbers[i];
   return sum;
}
void vector::add(int number)
{
   for (int i=0;i<10;i++)
      numbers[i]+=number;
}
void vector::add(int number, int place)
{
   numbers[place]+=number;
}
void vector::print()
{
   for (int i=0;i<10;i++)
      cout<<numbers[i]<<' ';
   cout<<endl;
}







