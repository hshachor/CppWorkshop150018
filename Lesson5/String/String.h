#pragma once

class String
{
private:
    char* str;
    void setString(const char* s);
public:
    // constructor.
    String(const char* s = nullptr);
    String(const String& s);
    ~String();

    // view function.
    char* getString() const;
    // modify function.
    String& operator =(const String&);

    // operators
    bool operator==(const String&) const;
    String  operator+(const String&);
    String  operator* (int); int length() const;

    // print
    void print() const;
};

