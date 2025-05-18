#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate area of square
double squareArea(double side)
{
  return side * side;
}

// Function to calculate area of circle
double circleArea(double radius)
{
  const double PI = 3.14159;
  return PI * radius * radius;
}

// Function to calculate area of rectangle
double rectangleArea(double length, double width)
{
  return length * width;
}

int main()
{
  double side, radius, length, width;

  cout << "Enter square side: ";
  cin >> side;
  cout << "Square area: " << squareArea(side) << endl;

  cout << "Enter circle radius: ";
  cin >> radius;
  cout << "Circle area: " << circleArea(radius) << endl;

  cout << "Enter rectangle length and width: ";
  cin >> length >> width;
  cout << "Rectangle area: " << rectangleArea(length, width) << endl;

  return 0;
}
