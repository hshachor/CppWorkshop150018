#pragma once
class SortAndPrint
{
protected:
    int size;
    virtual void swap(int i, int j) = 0;
    virtual void show(int i) const = 0;
    virtual int isSmaller(int i, int j) const = 0;
public:
    void setSize(int num);
    void print();
    void bubbleSort();
    virtual ~SortAndPrint() {};
};
