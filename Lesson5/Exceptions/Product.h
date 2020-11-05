#pragma once
#include <iosfwd>
class Product
{
private:
char name[10];
int quantity;
float price;
public:
    Product(){}
    void init(char* n, int q, float p);
    friend std::ostream& operator<<(std::ostream& os,Product p);
};
