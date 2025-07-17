//N Stacks In An Array

// link - https://www.naukri.com/code360/problems/n-stacks-in-an-array_1164271

/*
Design a data structure to implement ‘N’ stacks using a single array of size ‘S’. It should support the following operations:

push(X, M): Pushes an element X into the Mth stack. Returns true if the element is pushed into the stack, otherwise false.

pop(M): Pops the top element from Mth Stack. Returns -1 if the stack is empty, otherwise, returns the popped element.
Two types of queries denote these operations :

Type 1: for push(X, M) operation.
Type 2: for pop(M) operation.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= S <= 1000
1 <= Q <= 10^5 
1 <= P <= 2
1 <= X <= 10^5

Time Limit: 1 sec

Where ‘S’ represents the size of the array, ‘N’ represents the number of stacks, ‘Q’ represents the number of queries, ‘P’ represents the type of operation and ‘X’ represents the element.
Sample Input 1 :
3 6 5
1 10 1
1 20 1
1 30 2
2 1
2 2
Sample Output 1 :
True 
True
True
20
30
Explanation 1 :
For the given input, we have the number of stacks, N = 3, size of the array, S = 6 and number of queries, Q = 5.
Operations performed on the stack are as follows:
push(10, 1): Push element ‘10’ into the 1st stack. This returns true.
push(20, 1): Push element ‘20’ into the 1st stack. This returns true.
push(30, 2): Push element ‘30’ into the 2nd stack. This returns true.
pop(1): Pop the top element from the 1st stack. This returns 20.
pop(2): Pop the top element from the 2nd stack. This returns 30.

The following image shows the snapshots of the stack after each operation:

Sample Input 2 :
1 5 5
1 15 1
1 25 1
2 1
1 30 1
2 1
Sample Output 2 :
True
True
25
True
30
*/

#include <bits/stdc++.h>
using namespace std;

class NStack {
    int* arr;       // Array to store actual content
    int* top;       // Array to store indexes of top elements of stacks
    int* next;      // Array to store next entry in all stacks and free list
    int n, size;    // Number of stacks (n) and total size of array
    int freeSpot;   // Beginning index of free list

public:
    // Constructor
    NStack(int N, int S) {
        n = N;
        size = S;

        arr = new int[S];
        top = new int[N];
        next = new int[S];

        // Initialize all stacks as empty
        for (int i = 0; i < n; ++i)
            top[i] = -1;

        // Initialize all spaces as free and link them
        for (int i = 0; i < size - 1; ++i)
            next[i] = i + 1;
        next[size - 1] = -1;

        freeSpot = 0;  // First free slot is at index 0
    }

    // Destructor to release memory
    ~NStack() {
        delete[] arr;
        delete[] top;
        delete[] next;
    }

    // Push x into m-th stack (1-based indexing)
    bool push(int x, int m) {
        if (freeSpot == -1) {
            // No space left
            cout << "Stack Overflow\n";
            return false;
        }

        // Find index where to insert x
        int index = freeSpot;

        // Update freeSpot to next free position
        freeSpot = next[index];

        // Insert x into arr
        arr[index] = x;

        // Link the previous top of stack m to next of index
        next[index] = top[m - 1];

        // Update top of stack m
        top[m - 1] = index;

        return true;
    }

    // Pop top element from m-th stack (1-based indexing)
    int pop(int m) {
        if (top[m - 1] == -1) {
            // Stack m is empty
            cout << "Stack Underflow\n";
            return -1;
        }

        // Find index of top element of stack m
        int index = top[m - 1];

        // Update top to the next element in the stack
        top[m - 1] = next[index];

        // Add the current index to the beginning of free list
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }
};

int main() {
    int N = 3, S = 10;
    NStack st(N, S);

    // Sample pushes
    st.push(10, 1);
    st.push(20, 2);
    st.push(30, 1);
    st.push(40, 3);
    st.push(50, 1);
    st.push(60, 3);

    // Sample pops
    cout << "Popped from stack 1: " << st.pop(1) << endl; // 50
    cout << "Popped from stack 2: " << st.pop(2) << endl; // 20
    cout << "Popped from stack 3: " << st.pop(3) << endl; // 60
    cout << "Popped from stack 1: " << st.pop(1) << endl; // 30
    cout << "Popped from stack 1: " << st.pop(1) << endl; // 10
    cout << "Popped from stack 1: " << st.pop(1) << endl; // -1 (Underflow)

    return 0;
}
