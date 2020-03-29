#include <iostream>
#include "rational.h"
using namespace std;


void Rational::Zimzum(){
	int mmm = findMMM();
	x /= mmm;
	y /= mmm;
}

int Rational::findMMM(){

	int xx = x;
	int yy = y;
	int temp;
	while (xx % yy !=0 ){
		xx %= yy;
		if (xx<yy){
			temp=yy;
			yy=xx;
			xx=temp;
		}
	}
	return yy;
}


Rational::Rational(int m,int n){
	x=m;
	y=n;
	cout << "mmm is: " << findMMM() << endl;
	Zimzum();
	printR();
	printD();
}

Rational::~Rational(){
	return;
}

void Rational::printR(){
	cout << x << "/" << y << endl;
}

void Rational::printD(){
	float num = (float)x/y;
	cout << num << endl;
}



