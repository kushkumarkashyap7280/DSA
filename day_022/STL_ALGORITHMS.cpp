#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  // ================== ALGORITHMS ==================
  vector<int> v = {4, 2, 5, 1, 3};

  // Sorting
  sort(v.begin(), v.end());
  cout << "Sorted vector: ";
  for (int x : v)
    cout << x << " ";
  cout << endl;

  // Binary search
  bool found = binary_search(v.begin(), v.end(), 3);
  cout << "3 is " << (found ? "found" : "not found") << endl;

  // Min/Max
  auto min_it = min_element(v.begin(), v.end());
  auto max_it = max_element(v.begin(), v.end());
  cout << "Min: " << *min_it << ", Max: " << *max_it << endl;

  // Reverse
  reverse(v.begin(), v.end());
  cout << "Reversed: ";
  for (int x : v)
    cout << x << " ";
  cout << endl;

  return 0;
}
