#pragma once
#include "SortAndPrint.h"
class Numbers :
    public SortAndPrint
{
private:
    int* vec;
    void swap(int i, int j) override final;
    int isSmaller(int i, int j) const override final;
    void show(int i) const override final;
public:
    Numbers(int);
    virtual ~Numbers() { if (vec) delete[] vec; }

};

