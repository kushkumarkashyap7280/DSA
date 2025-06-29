// Function Overloading Example
#include <iostream>
#include <string>
using namespace std;

void print(int x) { cout << "Integer: " << x << endl; }
void print(double y) { cout << "Double: " << y << endl; }
void print(string s) { cout << "String: " << s << endl; }

int add(int a, int b) { return a + b; }
int add(int a, int b, int c) { return a + b + c; }

class Point
{
public:
  int x, y;
  Point() : x(0), y(0) {}
  Point(int a) : x(a), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

int main()
{
  print(5);
  print(3.14);
  print("Hello");
  cout << add(2, 3) << endl;
  cout << add(2, 3, 4) << endl;
  Point p1;
  Point p2(5);
  Point p3(2, 3);
  return 0;
}
