#include <iostream>
#include <queue>
using namespace std;

int main()
{
  // ================== PRIORITY QUEUE ==================
  // Definition: A container that provides constant time lookup of the largest element

  // Max Heap (default)
  priority_queue<int> maxHeap;

  // Min Heap
  priority_queue<int, vector<int>, greater<int>> minHeap;

  // Operations on Max Heap
  maxHeap.push(3);
  maxHeap.push(1);
  maxHeap.push(4);
  maxHeap.push(2);

  cout << "Max Heap elements (in decreasing order): ";
  while (!maxHeap.empty())
  {
    cout << maxHeap.top() << " "; // 4 3 2 1
    maxHeap.pop();
  }
  cout << endl;

  // Operations on Min Heap
  minHeap.push(3);
  minHeap.push(1);
  minHeap.push(4);
  minHeap.push(2);

  cout << "Min Heap elements (in increasing order): ";
  while (!minHeap.empty())
  {
    cout << minHeap.top() << " "; // 1 2 3 4
    minHeap.pop();
  }
  cout << endl;

  return 0;
}
