#include <iostream>
#include <map>
using namespace std;

int main()
{
  // ================== MAP ==================
  // Definition: Sorted key-value pairs container

  map<string, int> m;

  // Insertion
  m["apple"] = 1;
  m.insert({"banana", 2});
  m["orange"] = 3;

  // Access elements
  cout << "Value of apple: " << m["apple"] << endl;

  // Check if key exists
  if (m.count("banana"))
    cout << "banana exists in map" << endl;

  // Iteration
  cout << "Map elements:" << endl;
  for (const auto &pair : m)
  {
    cout << pair.first << ": " << pair.second << endl;
  }

  // Remove element
  m.erase("orange");

  return 0;
}
