#include <iostream>
#include <deque>  // deque library
using namespace std;

int main() {
   // ================== DEQUE ==================
    // Definition: Double-ended queue supporting fast insertion/removal from both ends

    deque<int> dq1;                       // Empty deque
    deque<int> dq2 = {1, 2, 3};           // Initialized with values
    deque<int> dq3(4, 50);                // Four elements with value 50

    // Insertion
    dq1.push_back(10);                   // Insert at back
    dq1.push_front(20);                  // Insert at front

    // Removal
    dq1.pop_back();                      // Remove from back
    dq1.pop_front();                     // Remove from front

    // Access
    dq2[1] = 100;
    cout << "Element at index 1 in dq2: " << dq2.at(1) << endl;
    cout << "Front: " << dq2.front() << ", Back: " << dq2.back() << endl;

    // Insert and Erase
    dq2.insert(dq2.begin() + 1, 77);     // Insert 77 at index 1
    dq2.erase(dq2.begin() + 2);          // Remove element at index 2

    // Size and Iteration
    cout << "Size of dq2: " << dq2.size() << endl;
    cout << "Elements in dq2: ";
    for (int x : dq2) cout << x << " ";
    cout << endl;

    // Clear deque
    dq3.clear();
    cout << "Is dq3 empty? " << (dq3.empty() ? "Yes" : "No") << endl;

    return 0;
}
