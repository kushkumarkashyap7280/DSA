#include <iostream>
#include <set>
using namespace std;

int main()
{
  // ================== SET ==================
  // Definition: Sorted container of unique elements

  set<int> s;

  // Insertion
  s.insert(30);
  s.insert(10);
  s.insert(20);
  s.insert(10); // Duplicate, won't be inserted

  // Size
  cout << "Set size: " << s.size() << endl;

  // Find element
  auto it = s.find(20);
  if (it != s.end())
    cout << "Found: " << *it << endl;

  // Remove element
  s.erase(10);

  // Print all elements
  cout << "Set elements: ";
  for (int x : s)
    cout << x << " ";
  cout << endl;

  return 0;
}
