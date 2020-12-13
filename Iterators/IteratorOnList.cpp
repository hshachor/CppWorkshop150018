#include <iostream>
#include "List.h"
using namespace std;

class IteratorOnList : public List
{
public:
    class iterator
    {
    private:
        Link* current;
        Link* headOfLst;
    public:
        iterator(Link* p, Link* q) :
            current(p), headOfLst(q) {}

        void operator++(int i)
        {
            Link* nextValue = headOfLst;
            while (nextValue && nextValue->value <= current->value)
                nextValue = nextValue->next;
            if (!nextValue) {
                current = nullptr;
                return;
            }
            Link* p = nextValue->next;
            while (p) {
                if (p->value > current->value && p->value < nextValue->value)
                    nextValue = p;
                p = p->next;
            }
            current = nextValue;
        }

        bool operator!=(iterator rhs) { return current != rhs.current; }
        int operator*() { return current->value; }
    };      //end of class iterator

    iterator begin()
    {
        if (isEmpty())
            return end();
        Link* min = head, * p = min->next;
        while (p) {
            if (p->value < min->value)
                min = p;
            p = p->next;
        }
        iterator it(min, this->head);
        return it;
    }

    iterator end()
    {
        iterator it(nullptr, nullptr);
        return it;
    }
};  //end of class IteratorOnList

int main()
{
    IteratorOnList lst;
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        lst.add(val);
        cout << val << ' ';
    }
    cout << endl;

    IteratorOnList::iterator it = lst.begin();
    for (; it != lst.end(); it++)
        cout << *it << ' ';
    cout << endl;
    return 0;
}

/*
Output:
41 67 34 0 69 24 78 58 62 64
0 24 34 41 58 62 64 67 69 78
*/