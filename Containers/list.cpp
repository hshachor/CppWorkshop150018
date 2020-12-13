#include <iostream>
#include <ctime>
#include <list>
using namespace std;

class A
{
protected:
    int a;
public:
    A() { a = rand() % 100; }
    virtual void print() { cout << "a=" << a << ' '; }
};

class B :public A
{
protected:
    int b;
public:
    B() :A() { b = rand() % 100; }
    void print() override { A::print(); cout << "b=" << b << ' '; }
};

class C :public B
{
protected:
    int c;
public:
    C() :B() { c = rand() % 100; }
    void print()override final { B::print(); cout << "c=" << c << ' '; }
};

int main()
{
    srand(time(nullptr));
    list<A*> lst;
    for (int i = 0; i < 5; i++) {
        A* ptr;
        int choice = rand() % 3;
        switch (choice) {
        case 0:
            ptr = new A();
            break;
        case 1:
            ptr = new B();
            break;
        case 2:
            ptr = new C();
            break;
        };
        lst.push_back(ptr);
    }
    list<A*>::iterator it = lst.begin();
    for (; it != lst.end(); it++) {
        (*it)->print();
        cout << endl;
    }
    return 0;
}