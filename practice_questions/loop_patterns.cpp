#include <iostream>
using namespace std;

// Question 1: Print number triangle
// 1
// 22
// 333
// 4444
void printNumberTriangle(int n)
{
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << i;
    }
    cout << endl;
  }
}

// Question 2: Print alphabet square
// ABCD
// ABCD
// ABCD
// ABCD
void printAlphabetSquare(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (char ch = 'A'; ch < 'A' + n; ch++)
    {
      cout << ch;
    }
    cout << endl;
  }
}

int main()
{
  cout << "Number Triangle:" << endl;
  printNumberTriangle(4);

  cout << "\nAlphabet Square:" << endl;
  printAlphabetSquare(4);
  return 0;
}
