// bubble sorting using recursion



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// fuction of bubble sorting
// Inner loop: Compare and swap
bool bubblePass(vector<int>& arr, int i, int j, bool swapped = false) {
    if (i >= j) return swapped;
    if (arr[i] > arr[i + 1]) {
        swap(arr[i], arr[i + 1]);
        swapped = true;
    }
    return bubblePass(arr, i + 1, j, swapped);
}

// Outer loop: Recursively call until no swaps
void bubbleSortRecursive(vector<int>& arr, int n) {
    if (n <= 1) return;
    bool swapped = bubblePass(arr, 0, n - 1);
    if (!swapped) return;
    bubbleSortRecursive(arr, n - 1);
}

int main() {
 // Example usage
  vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
  
  cout << "Original array: ";
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;

  bubbleSortRecursive(arr, arr.size());

  cout << "Sorted array: ";
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;
return 0;
}