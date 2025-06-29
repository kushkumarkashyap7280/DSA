// Polymorphism Example
#include <iostream>
using namespace std;

class Shape
{
public:
  virtual void draw() { cout << "Drawing shape" << endl; }
};
class Circle : public Shape
{
public:
  void draw() override { cout << "Drawing circle" << endl; }
};

int main()
{
  Shape *s = new Circle();
  s->draw(); // Output: Drawing circle
  delete s;
  return 0;
}
