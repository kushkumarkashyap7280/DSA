// 1381. Design a Stack With Increment Operation
//  Link: https://leetcode.com/problems/design-a-stack-with-increment-operation/

/*
Design a stack that supports increment operations on its elements.

Implement the CustomStack class:

CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
int pop() Pops and returns the top of the stack or -1 if the stack is empty.
void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.
*/

#include <iostream>
using namespace std;

// custom stack

class CustomStack
{
    int index;
    int size;
    int *arr;

public:
    // Time: O(1), Space: O(N)
    CustomStack(int maxSize)
    {
        index = -1;
        size = maxSize;
        arr = new int[maxSize];
    }

    // Time: O(1), Space: O(1)
    void push(int x)
    {
        if (index + 1 < size)
        {
            index++;
            arr[index] = x;
        }
        return;
    }

    // Time: O(1), Space: O(1)
    int pop()
    {
        if (index == -1)
            return -1;
        int ans = arr[index];
        index--;
        return ans;
    }

    // Time: O(min(k, N)), Space: O(1)
    void increment(int k, int val)
    {
        if (index == -1)
            return;
        for (int i = 0; i < min(k, index + 1); i++)
        {
            arr[i] += val;
        }
        return;
    }

    // Utility: print stack from bottom to top
    void print()
    {
        cout << "Stack (bottom to top): ";
        for (int i = 0; i <= index; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor to free memory
    ~CustomStack()
    {
        delete[] arr;
    }
};

int main()
{
    CustomStack stk(3);                   // Stack is Empty []
    stk.push(1);                          // stack becomes [1]
    stk.push(2);                          // stack becomes [1, 2]
    cout << "Pop: " << stk.pop() << endl; // return 2, stack becomes [1]
    stk.push(2);                          // stack becomes [1, 2]
    stk.push(3);                          // stack becomes [1, 2, 3]
    stk.push(4);                          // stack still [1, 2, 3], no change
    stk.increment(5, 100);                // stack becomes [101, 102, 103]
    stk.increment(2, 100);                // stack becomes [201, 202, 103]
    cout << "Pop: " << stk.pop() << endl; // return 103, stack becomes [201, 202]
    cout << "Pop: " << stk.pop() << endl; // return 202, stack becomes [201]
    cout << "Pop: " << stk.pop() << endl; // return 201, stack becomes []
    cout << "Pop: " << stk.pop() << endl; // return -1, stack is empty
    return 0;
}