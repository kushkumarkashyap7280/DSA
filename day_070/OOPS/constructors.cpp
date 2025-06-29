// Constructors Example
#include <iostream>
using namespace std;

class Point
{
public:
  int x, y;
  // Default constructor
  Point() : x(0), y(0) {}
  // Parameterized constructor
  Point(int a, int b) : x(a), y(b) {}
  // Copy constructor
  Point(const Point &p) : x(p.x), y(p.y) {}
  // Destructor
  ~Point() { cout << "Destroyed" << endl; }
};

int main()
{
  Point p1;       // Default
  Point p2(3, 4); // Parameterized
  Point p3 = p2;  // Copy
  return 0;
}
