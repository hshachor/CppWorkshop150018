#include <iostream>
using namespace std;

#define EXAMPLE_NUM 1

class A
{
private:
    char* str1;
public:
    A(const char* str);
#if EXAMPLE_NUM == 3
    virtual
#endif
        ~A();
};
A::A(const char* str)
{
    cout << "A constructor\n";
    str1 = new char[strlen(str) + 1];
    strcpy_s(str1, strlen(str)+1, str);
}
A::~A()
{
    cout << "A destructor\n";
    if (str1)
        delete str1;;
}

class B :public A
{
private:
    char* str2;
public:
    B(const char* str);
    ~B()
#if EXAMPLE_NUM == 3
        override
#endif
        ;
};
B::B(const char* str) : A(str)
{
    cout << "B constructor\n";
    str2 = new char[strlen(str) + 1];
    strcpy_s(str2, strlen(str) + 1, str);;
}
B::~B()
{
    cout << "B destructor\n";

    if (str2)
        delete str2;
}


int main()
{
#if EXAMPLE_NUM == 1
    A aa("test A");
    B bb("test B");
#else
    A* ab = new B("test ab");
    delete ab;
#endif
    return 0;
}

/*output:

Example 1:
A constructor
A constructor
B constructor
B destructor
A destructor
A destructor

Example 2:
A constructor
B constructor
A destructor

Example 3:
A constructor
B constructor
B destructor
A destructor

*/
