#include <iostream>
using namespace std;

class Point
{
	int x = 0;
	int y = 0;
public:
	Point() { cout << " in  ctor\n"; }
	Point(int _x, int _y) :x(_x), y(_y) { cout << " in  ctor\n"; }
	Point(const Point& p) :x(p.x), y(p.y) { cout << " in cctor\n"; }
	//~Point() {}
	//Point& operator=(const Point& rhs) { x = rhs.x; y = rhs.y; cout << " enter operator=\n"; return *this; }
	void print() {
		cout << " ( " << x << "," << y << " ) " << endl;
	}
};

int main()
{

	Point p1;
	Point p2(4, 5);
	p1.print();
	p2.print();
}