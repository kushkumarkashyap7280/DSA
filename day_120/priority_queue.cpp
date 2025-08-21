// ================ priority queue ==========


#include <iostream>
#include <queue>
using namespace std;
int main() {

  // max heap
  priority_queue<int> pq;
  pq.push(10);
  pq.push(5);
  pq.push(20);
  cout << "Size of priority queue: " << pq.size() << endl;
  cout << "if pq is empty: " << (pq.empty() ? "Yes" : "No") << endl;
  cout << "Top element: " << pq.top() << endl;
  pq.pop();
  cout << "Top element after pop: " << pq.top() << endl;


  // min heap
  priority_queue<int, vector<int>, greater<int>> minHeap;
  minHeap.push(10);
  minHeap.push(5);
  minHeap.push(20);
  cout << "Size of min heap: " << minHeap.size() << endl;
  cout << "if min heap is empty: " << (minHeap.empty() ? "Yes" : "No") << endl;
  cout << "Top element: " << minHeap.top() << endl;
  minHeap.pop();
  cout << "Top element after pop: " << minHeap.top() << endl;

  return 0;
}