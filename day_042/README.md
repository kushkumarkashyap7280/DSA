# Day 42 - Understanding Recursion with Fibonacci Numbers

## Recursion Overview

Recursion is a programming concept where a function calls itself to solve a problem by breaking it down into smaller subproblems.

### Key Concepts of Recursion:

1. **Base Case**: The condition that stops recursion (prevents infinite calls)
2. **Recursive Case**: The part where function calls itself with modified parameters
3. **Call Stack**: Memory used to keep track of function calls

## Example: Fibonacci Sequence using Recursion

### Problem ([LeetCode 509](https://leetcode.com/problems/fibonacci-number/))

Calculate the nth number in the Fibonacci sequence using recursion.

### Recursive Approach

```cpp
int fibonacci(int n) {
    // Base case
    if (n == 0 || n == 1) return n;

    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

### Analysis

- **Time Complexity**: O(2ⁿ) - Each call creates two more calls
- **Space Complexity**: O(n) - Maximum depth of recursion tree

### Recursion Tree for fibonacci(4)

```
                    fib(4)
                /           \
            fib(3)          fib(2)
           /      \        /      \
      fib(2)     fib(1)  fib(1)  fib(0)
     /      \
fib(1)     fib(0)
```

### Advantages of Recursion

- Clean and elegant code
- Complex problems become easier to understand
- Natural solution for problems with recursive structure

### Disadvantages of Recursion

- High memory usage due to call stack
- Slower execution compared to iterative solutions
- Risk of stack overflow for large inputs

## Alternative Iterative Solution

```cpp
int fibonacci(int n) {
    if (n <= 1) return n;
    int a = 0, b = 1;
    for(int i = 2; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
```

- **Time Complexity**: O(n)
- **Space Complexity**: O(1)

## When to Use Recursion

1. When the problem can be broken down into similar subproblems
2. When working with tree-like data structures
3. When code readability is more important than performance
4. When dealing with problems that have recursive mathematical definitions
