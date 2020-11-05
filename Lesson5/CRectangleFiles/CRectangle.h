#pragma once
#include "CSquare.h"

class CSquare;

class CRectangle
{
private:
    int width, height;
public:
    int area() const { return (width * height); }
    void convert(CSquare a);
};
