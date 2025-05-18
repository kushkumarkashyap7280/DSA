#include <iostream>
#include <stack>  // stack library
using namespace std;

int main() {
   // ================== STACK ==================
    // Definition: LIFO (Last-In, First-Out) structure used for storing elements

    stack<int> stk1;                    // Empty stack
    stack<int> stk2;                    // Another empty stack

    // Push elements
    stk1.push(10);
    stk1.push(20);
    stk1.push(30);

    // Access top element
    cout << "Top element in stk1: " << stk1.top() << endl;

    // Pop elements
    stk1.pop();
    cout << "Top element after pop: " << stk1.top() << endl;

    // Check if stack is empty
    cout << "Is stk2 empty? " << (stk2.empty() ? "Yes" : "No") << endl;

    // Size of stack
    cout << "Size of stk1: " << stk1.size() << endl;

    return 0;
}
