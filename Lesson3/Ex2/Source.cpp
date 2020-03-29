#include <iostream>
//#include "vector2.h"
#include "Rational.h"
using namespace std;

int main()
{
	//vector2 v1;
	//vector2 v2;
	Rational r1;
	Rational r2(3, 4);
	Rational r3(5, 6);
	Rational r4(r3);
	Rational r5 = r4;
	Rational r6 = r5++;
	Rational r7 = ++r5;
	cout << "r1:" << r1 << " r2:" << r2 << " r6:" << r6 << "r7:" << r7;
	return 0;

}