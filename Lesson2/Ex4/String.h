#pragma once
#include <iostream>
using namespace std;

class String 
{
	int _len = 0; 
	char* _data;
public:
	String() : _data(nullptr) {}
	String(const char* p);
	~String() { delete[] _data; }

	// copy constructor
	String(const String& s) : String(s._data) { cout << "cctor\n"; }

	// move constructor
	String(String&& s);

	int Length() const { return _len; }
	bool Find(const String& s) const { return strstr(_data, s._data) != nullptr; }
	
	void print() { cout << _data << endl; }
};
