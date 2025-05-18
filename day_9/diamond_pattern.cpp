#include <iostream>
using namespace std;

void printDiamond(int n)
{
  // Upper half
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
      cout << " ";
    for (int j = 0; j <= i; j++)
      cout << "* ";
    cout << endl;
  }

  // Lower half
  for (int i = n - 2; i >= 0; i--)
  {
    for (int j = 0; j < n - i - 1; j++)
      cout << " ";
    for (int j = 0; j <= i; j++)
      cout << "* ";
    cout << endl;
  }
}

int main()
{
  int n = 5;
  cout << "Diamond Pattern:" << endl;
  printDiamond(n);
  return 0;
}
