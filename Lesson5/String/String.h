#pragma once

// This class represent string object, and handle all allocation without (supposedly) memory leak.
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
    const char* getString() const;

    // modify function.
    String& operator =(const String&);

    // operators
    bool operator==(const String&) const;
    String operator+(const String&) const;
    String operator* (int) const;

    int length() const;

    // print
    void print() const;
};

