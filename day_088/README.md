## Leetcode 85: Maximal Rectangle

**Problem Link:** [Leetcode 85 - Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)
**Solution File:** [Leetcode_85.cpp](./Leetcode_85.cpp)

**Problem:**
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

**Approach:**

- For each row, treat it as the base of a histogram where the height of each bar is the number of consecutive '1's above (including) the current row.
- For each row's histogram, use a stack-based approach to find the largest rectangle in a histogram (same as Leetcode 84).
- Update the maximal area found so far.

**Time Complexity:** O(rows × cols)
**Space Complexity:** O(cols)

**Code Snippet:**

```cpp
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using std::vector;
using std::stack;
using std::max;

class Solution
{
public:
  int maximalRectangle(vector<vector<char>> &matrix)
  {
    if (matrix.empty())
      return 0;

    int maxArea = 0;
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> heights(cols, 0);

    for (int i = 0; i < rows; ++i)
    {
      // Build histogram for current row
      for (int j = 0; j < cols; ++j)
      {
        if (matrix[i][j] == '1')
        {
          heights[j] += 1;
        }
        else
        {
          heights[j] = 0;
        }
      }
      maxArea = max(maxArea, largestRectangleArea(heights));
    }
    return maxArea;
  }

  int largestRectangleArea(vector<int> &heights)
  {
    stack<int> s;
    heights.push_back(0); // Sentinel
    int maxArea = 0;

    for (int i = 0; i < heights.size(); ++i)
    {
      while (!s.empty() && heights[i] < heights[s.top()])
      {
        int h = heights[s.top()];
        s.pop();
        int w = s.empty() ? i : (i - s.top() - 1);
        maxArea = max(maxArea, h * w);
      }
      s.push(i);
    }

    heights.pop_back(); // Remove sentinel
    return maxArea;
  }
};

int main() {
    Solution sol;
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };
    int result = sol.maximalRectangle(matrix);
    std::cout << "Maximal Rectangle Area: " << result << std::endl;
    return 0;
}
```

---

## N Stacks In An Array

**Problem Link:** [N Stacks In An Array - Coding Ninjas](https://www.naukri.com/code360/problems/n-stacks-in-an-array_1164271)
**Solution File:** [N_stack_in_an_array.cpp](./N_stack_in_an_array.cpp)

**Problem:**
Design a data structure to implement ‘N’ stacks using a single array of size ‘S’. It should support push and pop operations for each stack efficiently.

**Approach:**

- Use three arrays: `arr` (to store stack elements), `top` (to store the top index for each stack), and `next` (to manage free spots and stack links).
- Maintain a `freeSpot` pointer to the first free index in `arr`.
- For push: Place the element at `freeSpot`, update links, and move `freeSpot`.
- For pop: Remove the top element from the specified stack, update links, and add the freed index back to the free list.
- All operations are O(1).

**Time Complexity:** O(1) per operation
**Space Complexity:** O(N + S)

**Code Snippet:**

```cpp
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
```
