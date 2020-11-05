#include "String.h"
#include <cstring>
#include <iostream>

String::String(const char* s)
{
    setString(s);
}

String::String(const String& s)
{
    setString(s.getString());
}

String::~String()
{
    if (str)
        delete[] str;
    str = nullptr;
}

char* String::getString() const
{
    return str;
}

void String::setString(const char* s)
{
    if (s) {
        int len = strlen(s) + 1;
        str = new char[len];
        strcpy_s(str, len, s);
    }
    else
        str = nullptr;
}

String& String::operator=(const String& s)
{
    if (str)
        delete[] str;
    setString(s.getString());
    return *this;
}

String String::operator+(const String& s)
{
    int sizeI = strlen(str);
    int sizeII = strlen(s.getString());
    char* temp = new char[sizeI + sizeII + 1];
    strcpy_s(temp, sizeI + 1, str);
    strcpy_s(temp + sizeI, sizeII + 1, s.getString());
    String x(temp);
    return x;
}

String String::operator*(const int num)
{
    char* temp;
    int len = strlen(str);
    temp = new char[len * num + 1];
    for (int i = 0; i < num; i++)
        strcpy_s(temp + i * len, len + 1, str);
    String s(temp);
    return s; // or: return String(temp) - no copy ctor...
}

bool String::operator==(const String& s) const
{
    return !strcmp(str, s.getString());
}

int String::length() const
{
    return strlen(str);
}

void String::print() const
{
    if (str)
        std::cout << str << std::endl;
}