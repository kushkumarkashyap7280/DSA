#include <iostream>
#include <queue>  // queue library
using namespace std;

int main() {
 // ================== QUEUE ==================
    // Definition: FIFO (First-In, First-Out) structure used for storing elements

    queue<int> q1;                      // Empty queue
    queue<int> q2;                      // Another empty queue

    // Enqueue elements
    q1.push(10);
    q1.push(20);
    q1.push(30);

    // Access front and back elements
    cout << "Front element in q1: " << q1.front() << endl;
    cout << "Back element in q1: " << q1.back() << endl;

    // Dequeue elements
    q1.pop();
    cout << "Front element after pop: " << q1.front() << endl;

    // Check if queue is empty
    cout << "Is q2 empty? " << (q2.empty() ? "Yes" : "No") << endl;

    // Size of queue
    cout << "Size of q1: " << q1.size() << endl;
    return 0;
}
