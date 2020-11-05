#include <iostream>
#include "CSquare.h"

using std::cout;

int main() {
    CSquare sqr;
    CRectangle rect;
    sqr.set_side(4);
    rect.convert(sqr);
    cout << rect.area();
    return 0;
}
