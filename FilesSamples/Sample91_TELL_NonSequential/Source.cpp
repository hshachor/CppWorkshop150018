#include<fstream>
#include<string>
#include<iostream>
using namespace std;


int main()
{
	ifstream is("test.txt", ifstream::binary);
	if (is)
	{
		// get length of file:
		is.seekg(0, ios::end);
		int length = is.tellg();
		is.seekg(0, ios::beg);
		char* buffer = new char[length];// allocate memory:		
		is.read(buffer, length);// read data as a block
		is.close();
		cout.write(buffer, length);// print content to screen
		delete[] buffer;
	}

}