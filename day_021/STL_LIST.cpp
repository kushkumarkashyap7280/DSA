#include <iostream>
#include <list>  // list library
using namespace std;

int main() {
   // ================== LIST ==================
    // Definition: Doubly linked list allowing fast insertion/deletion at any position

    list<int> lst1;                      // Empty list
    list<int> lst2 = {10, 20, 30};       // Initialized with values
    list<int> lst3(3, 99);               // Three elements with value 99

    // Insertion
    lst1.push_back(5);                  // Add at end
    lst1.push_front(1);                 // Add at beginning

    // Deletion
    lst1.pop_back();                   // Remove from end
    lst1.pop_front();                  // Remove from beginning

    // Iteration
    cout << "Elements of lst2: ";
    for (int x : lst2) cout << x << " ";
    cout << endl;

    // Insert and Erase using iterator
    auto it = lst2.begin();
    advance(it, 1);                    // Move iterator to second element
    lst2.insert(it, 15);              // Insert before second element

    it = lst2.begin();
    advance(it, 2);                    // Move to third element
    lst2.erase(it);                   // Erase that element

    // Size and Clear
    cout << "Size of lst2: " << lst2.size() << endl;
    lst3.clear();
    cout << "Is lst3 empty? " << (lst3.empty() ? "Yes" : "No") << endl;

    return 0;
}
