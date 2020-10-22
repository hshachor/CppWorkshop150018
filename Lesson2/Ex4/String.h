#pragma once

class String 
{
	int _len = 0; 
	char* _data;
public:
	String() : _data(nullptr) {}
	String(const char* p);
	~String() { delete[] _data; }

	// copy constructor
	String(const String& s);

	// move constructor
	String(String&& s);

	// what about assignment?

	int Length() const { return _len; }
	bool Find(const String& s) const { return strstr(_data, s._data) != nullptr; }
	
	void print();
};
