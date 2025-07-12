// Delete Middle Element of a Stack

// Link: https://www.geeksforgeeks.org/problems/delete-middle-element-of-a-stack/1


// Recursive function to delete the middle element
// ✅ Time complexity:
// 𝑂(𝑁)
// ✅ Space complexity:
// 𝑂(𝑁)

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    // Helper to delete middle element
    void deleteRecursive(stack<int>& s, int index, int mid) {
        if (index == mid) {
            s.pop();  // remove middle
            return;
        }

        int temp = s.top();
        s.pop();
        deleteRecursive(s, index + 1, mid);
        s.push(temp);  // restore
    }

    // Wrapper function
    void deleteMid(stack<int>& s) {
        if (s.empty()) return;

        int l = s.size() - 1;
        deleteRecursive(s, 0, l / 2);
    }
};

// Utility function: copy stack & iterate
void printStack(stack<int> s) {
    cout << "Stack (top to bottom): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;

    // Push elements only ONCE
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Original stack: ";
    printStack(s);

    Solution sol;
    sol.deleteMid(s);

    cout << "Stack after deleting middle element: ";
    printStack(s);

    return 0;
}
