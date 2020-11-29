#include <iostream>
using namespace std;
#define Example 5
#if Example == 1
class A
{
public:
    virtual void print() { cout << "A "; }
};

class B : public A
{
public:
    void print() { cout << "B "; }
};

class C : public B
{
public:
    void print() { cout << "C "; }
};

void main()
{
    system("color 9f");
    A** p = new A * [3];
    p[0] = new A;
    p[1] = new B;
    p[2] = new C;
    for (int i = 0; i < 3; i++)
        p[i]->print();
    B* pb;
    //pb = p[2];
    pb = (C*)p[2];

    pb->print();
    cout << endl;
}
#endif

#if Example == 2

#include<iostream>
using namespace std;

class a {
public:
    a();
    virtual void draw();
    void paint();
    void print();
};

a::a() {
    cout << "class a constructor" << endl;
}
void a::draw() {
    cout << "draw of a" << endl;
}
void a::paint() {
    cout << "paint of a" << endl;
}
void a::print() {
    draw();
    paint();
}

class b :public a {
public:
    b();
    virtual  void draw();
    void paint();
};

b::b() {
    cout << "class b constructor " << endl;
}
void b::draw() {
    cout << "draw of b" << endl;
}
void b::paint() {
    cout << "paint of b" << endl;
}

class c :public b {
public:
    c();
    void draw();
    void paint();
};

c::c() {
    cout << "class c constructor" << endl;
}
void c::draw() {
    cout << "draw of c" << endl;
}
void c::paint() {
    cout << "paint of c" << endl;
}


void function(a& x)
{
    x.print();
}

void main()
{
    system("color 9f");
    a A;
    b B;
    c C;
    function(A);
    function(B);
    function(C);
}


#endif

#if Example == 3

#include<iostream>
using namespace std;

class EE
{
public:
    void f() { f1(); f2(); }
    virtual void f1() { cout << "EE::f1()" << endl; }
    virtual void f2() { cout << "EE::f2()" << endl; }
};
class FF :public EE
{
public:
    void f1() { cout << "FF::f1()" << endl; }
    void f2() { cout << "FF::f2()" << endl; }
};

class GG :public FF
{
    void f() { cout << "GG::f()"; };
    void f1() { cout << "GG::f1()" << endl; }
    // demonstrate without f2
    void f2() { cout << "GG::f2()" << endl; }
};


void main()
{
    GG g1;
    EE* p = &g1;
    p->f();
}

#endif
#if Example == 4
#include "StackList.h"
#include "StackVector.h"
int main()
{
    try {
        Stack* st;
        char base[7];
        cout << "Do you want a list base or a vector base?";
        cin >> base;
        if (strcmp(base, "vector") == 0)
            st = new StackVector(20);
        else
            st = new StackList();
        for (int i = 0; i < 20; i++)
            st->push(i);
        while (!st->isEmpty())
            cout << st->pop() << " ";
    }
    catch (char* str) {
        cout << str;
    }
    return 0;
}

#endif
#if Example == 5
#include "QueueList.h"
#include "QueueVector.h"

int main() {
    Queue* Q;
    char base[7];
    cout << "Do you want a list or a vector base Queue? ";
    cin >> base;
    if (!strcmp(base, "vector"))
        Q = new QueueVector(10);
    else
        Q = new QueueList();
    try {
        for (int i = 0; i < 10; i++)
            Q->enqueue(i);
    }
    catch (const char* msg) { 
        cout << msg; 
    }
    cout << "first on Q is: " << Q->front() << endl;
    cout << "take out 2 elemets:" << endl;
    cout << Q->dequeue() << ' ' << Q->dequeue() << endl;
    cout << "first on Q is: " << Q->front() << endl;
    Q->enqueue(8);
    Q->enqueue(9);
    while (!Q->isEmpty())
        cout << Q->dequeue() << " ";
    return 0;
}

#endif


