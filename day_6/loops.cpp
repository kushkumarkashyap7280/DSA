#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // 1. FOR LOOP
  cout << "=== Basic for loop ===" << endl;
  for (int i = 1; i <= 5; i++)
  {
    cout << i << " ";
  }
  cout << endl;

  // 2. WHILE LOOP
  cout << "\n=== While loop ===" << endl;
  int count = 5;
  while (count > 0)
  {
    cout << count << " ";
    count--;
  }
  cout << endl;

  // 3. DO-WHILE LOOP
  cout << "\n=== Do-While loop ===" << endl;
  int num = 1;
  do
  {
    cout << num << " ";
    num++;
  } while (num <= 5);
  cout << endl;

  // 4. RANGE-BASED FOR LOOP (C++11)
  cout << "\n=== Range-based for loop ===" << endl;
  vector<int> nums = {1, 2, 3, 4, 5};
  for (const auto &n : nums)
  {
    cout << n << " ";
  }
  cout << endl;

  // 5. NESTED LOOPS
  cout << "\n=== Nested loops (Pattern) ===" << endl;
  for (int i = 1; i <= 3; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << "* ";
    }
    cout << endl;
  }

  // 6. INFINITE LOOP WITH BREAK
  cout << "\n=== Break statement ===" << endl;
  int i = 1;
  while (true)
  {
    if (i > 5)
      break;
    cout << i++ << " ";
  }
  cout << endl;

  // 7. CONTINUE STATEMENT
  cout << "\n=== Continue statement (skip even numbers) ===" << endl;
  for (int i = 1; i <= 10; i++)
  {
    if (i % 2 == 0)
      continue;
    cout << i << " ";
  }
  cout << endl;

  // 8. LOOP WITH MULTIPLE VARIABLES
  cout << "\n=== Loop with multiple variables ===" << endl;
  for (int i = 1, j = 10; i <= 5; i++, j--)
  {
    cout << i << ":" << j << " ";
  }
  cout << endl;

  return 0;
}
