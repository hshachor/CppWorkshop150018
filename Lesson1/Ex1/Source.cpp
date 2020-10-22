#include <iostream>
#pragma warning( disable : 4700 )
using namespace std;

class Rational
{
public:
	int numerator;
	int denominator;
};

int main() {
	Rational  num1, num2;
	Rational* pNum = new Rational;
	/*
	num1.numerator = 2;
	num1.denominator = 4;
	*/
	num2.numerator = 3;
	num2.denominator = 6;

	pNum->numerator = 4;
	pNum->denominator = 8;

	cout << num1.numerator << '/' << num1.denominator << endl;
	cout << num2.numerator << '/' << num2.denominator << endl;
	cout << pNum->numerator << '/' << pNum->denominator << endl;


	return 0;
}
