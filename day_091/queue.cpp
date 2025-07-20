// =================== QUEUE =======================
// Demonstration of std::queue in C++

#include <iostream>
#include <queue>
using namespace std;

// Helper function to print all elements in the queue (by value)
void printQueue(queue<int> q)
{
  cout << "Queue: ";
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}

int main()
{
  queue<int> q;

  // Push elements
  cout << "Pushing 5, 6, 7 into the queue..." << endl;
  q.push(5);
  q.push(6);
  q.push(7);
  printQueue(q);

  // Size and front
  cout << "Size: " << q.size() << endl;
  cout << "Front: " << q.front() << endl;
  cout << "Back: " << q.back() << endl;

  // Pop an element
  cout << "Popping front element..." << endl;
  q.pop();
  printQueue(q);
  cout << "Front: " << q.front() << endl;
  cout << "Size: " << q.size() << endl;

  // Check if empty
  cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

  // Clear the queue
  cout << "Clearing the queue..." << endl;
  while (!q.empty())
    q.pop();
  cout << "Is queue empty after clearing? " << (q.empty() ? "Yes" : "No") << endl;

  return 0;
}