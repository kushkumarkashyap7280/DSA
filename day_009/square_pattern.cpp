#include <iostream>
using namespace std;

void printSquare(int n)
{
  // Square/Rectangle pattern
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << "* ";
    }
    cout << endl;
  }
}

void printHollowSquare(int n)
{
  // Hollow square pattern
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
        cout << "* ";
      else
        cout << "  ";
    }
    cout << endl;
  }
}

int main()
{
  int n = 5;
  cout << "Solid Square Pattern:" << endl;
  printSquare(n);
  cout << "\nHollow Square Pattern:" << endl;
  printHollowSquare(n);
  return 0;
}
