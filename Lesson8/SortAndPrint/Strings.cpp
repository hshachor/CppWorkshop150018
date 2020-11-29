#include "Strings.h"
#include <iostream>
#include <cstring>

using namespace std;

Strings::Strings(const char* w0, const char* w1, const char* w2, const char* w3)
{
	setSize(4);
	strcpy_s(words[0], w0);
	strcpy_s(words[1], w1);
	strcpy_s(words[2], w2);
	strcpy_s(words[3], w3);
}

int Strings::isSmaller(int i, int j) const 
{
	return strcmp(words[i], words[j]) < 0;
}

void Strings::swap(int i, int j)
{
	char tmp[20];
	strcpy_s(tmp, words[i]);
	strcpy_s(words[i], words[j]);
	strcpy_s(words[j], tmp);
}

void Strings::show(int i) const 
{
	cout << i << " : " << words[i] << endl;
}
