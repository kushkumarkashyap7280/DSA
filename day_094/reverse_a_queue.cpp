#include <iostream>
#include <queue>
#include <stack>
#include <vector>

// Queue Reversal

// link - https://www.geeksforgeeks.org/problems/queue-reversal/1

/*
Given a queue q containing integer elements, your task is to reverse the queue.

Examples:

Input: q[] = [4 3 1 10 2 6]
Output: [6, 2, 10, 1, 3, 4]
Explanation: After reversing the given elements of the queue, the resultant queue will be 6 2 10 1 3 4.
Input: q[] = [4 3 2 1]
Output: [1, 2, 3, 4]
Explanation: After reversing the given elements of the queue, the resultant queue will be 1 2 3 4.
Input: q[] = [7, 9, 5, 12, 8]
Output: [8, 12, 5, 9, 7]
Explanation: After reversing the given elements of the queue, the resultant queue will be 8, 12, 5, 9, 7.
Constraints:
1 ≤ q.size() ≤ 106
1 ≤ q[i] ≤ 105
*/

// Approach 1: Using an auxiliary array
// Time Complexity: O(N), where N is the number of elements in the queue.
// Space Complexity: O(N) for the auxiliary array.
std::queue<int> reverseQueueWithArray(std::queue<int> &q) {
        int s = q.size();
       int * arr = new int[s];
       int j = s-1;
       while(!q.empty()){
           arr[j] = q.front();
           q.pop();
           j--;
       }
       
       for(int i = 0; i < s; i++){
           q.push(arr[i]);
       }
       
       delete [] arr;
       return q;
    }


// Approach 2: Using a stack
// Time Complexity: O(N), where N is the number of elements in the queue.
// Space Complexity: O(N) for the auxiliary stack.

std::queue<int> reverseQueue(std::queue<int> &q) {
    if (q.empty()) return q;

    int f = q.front();   // store the front
    q.pop();

    reverseQueue(q);     // reverse the rest

    q.push(f);           // push the front to back
    return q;
}

// Approach 3: Using Recursion
// Time Complexity: O(N) due to the recursive calls and pushing elements back.
// Space Complexity: O(N) for the recursion call stack.
std::queue<int> reverseQueueWithStack(std::queue<int>& q) {
        std::stack<int> st;

        while (!q.empty()) {
            st.push(q.front());
            q.pop();
        }

        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        return q;
    }

std::queue<int> reverseQueueusingrecursion(std::queue<int> &q) {
        if (q.empty()) return q;
    
        int f = q.front();   // store the front
        q.pop();
    
        reverseQueue(q);     // reverse the rest
    
        q.push(f);           // push the front to back
        return q;
}
    


void printQueue(std::queue<int> q) {
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

int main() {
    // Create a queue
    std::queue<int> q;
    q.push(4);
    q.push(3);
    q.push(1);
    q.push(10);
    q.push(2);
    q.push(6);

    std::cout << "Original queue: ";
    printQueue(q);

    // Reverse the queue using the stack approach
    // Reverse the queue using the recursive approach
    q = reverseQueueusingrecursion(q);

    std::cout << "Reversed queue: ";
    printQueue(q);

    return 0;
}