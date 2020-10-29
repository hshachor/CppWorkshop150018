
#include "vector.h"
#include <iostream>
using namespace std;

void printVec(Vector v) 
{
    v.print();
}

void main()
{
   int nums[10];
   for (int i=0;i<10;i++)
      nums[i]=i;
    Vector vec1, 
        vec2(6), 
        vec3(4,8), 
        vec4(nums), 
        vec5(vec3), 
        vec6 = vec1;

   vec6.print();
}
