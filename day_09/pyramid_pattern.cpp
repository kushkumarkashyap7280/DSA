#include <iostream>
using namespace std;

void printPyramid(int n)
{
  // Regular pyramid
  for (int i = 0; i < n; i++)
  {
    // Print spaces
    for (int j = 0; j < n - i - 1; j++)
      cout << " ";
    // Print stars
    for (int j = 0; j <= i; j++)
      cout << "* ";
    cout << endl;
  }
}

void printInvertedPyramid(int n)
{
  // Inverted pyramid
  for (int i = n; i > 0; i--)
  {
    // Print spaces
    for (int j = 0; j < n - i; j++)
      cout << " ";
    // Print stars
    for (int j = 0; j < i; j++)
      cout << "* ";
    cout << endl;
  }
}

int main()
{
  int n = 5;
  cout << "Pyramid Pattern:" << endl;
  printPyramid(n);
  cout << "\nInverted Pyramid Pattern:" << endl;
  printInvertedPyramid(n);
  return 0;
}
