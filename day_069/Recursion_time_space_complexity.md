# Recursion: Time and Space Complexity Analysis

This note explains how to analyze the time and space complexity of recursive algorithms, including single recursion (like factorial, Fibonacci), divide-and-conquer (merge sort, quick sort), and backtracking (e.g., Rat in a Maze, N-Queens).

---

## 1. Single Recursive Calls

### Example: Factorial

```cpp
int fact(int n) {
    if (n == 0) return 1;
    return n * fact(n-1);
}
```

- **Time Complexity:** O(n)
  - Each call reduces `n` by 1, so there are `n` calls.
- **Space Complexity:** O(n)
  - Each call is on the call stack until the base case.

### Example: Fibonacci (Naive)

```cpp
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}
```

- **Time Complexity:** O(2^n)
  - Each call spawns two more calls, forming a binary tree of height n.
- **Space Complexity:** O(n)
  - The deepest call stack is n (for the leftmost branch).

---

## 2. Divide and Conquer

### Example: Merge Sort

```cpp
void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}
```

- **Time Complexity:** O(n log n)
  - At each level, the array is split in half (log n levels), and merging takes O(n) per level.
- **Space Complexity:** O(n)
  - Temporary arrays for merging.

### Example: Quick Sort

- **Time Complexity:**
  - Best/Average: O(n log n)
  - Worst: O(n^2) (if pivot is always min/max)
- **Space Complexity:** O(log n) (due to recursion stack)

---

## 3. Backtracking

### Example: Rat in a Maze

```cpp
void addpath(vector<string> &ans, vector<vector<int>> &maze, int s, string &str, int i, int j) {
    if (i == s - 1 && j == s - 1) {
        ans.push_back(str);
        return;
    }
    maze[i][j] = 0;
    // D, L, R, U moves
    if (i + 1 < s && maze[i + 1][j] == 1) { str.push_back('D'); addpath(ans, maze, s, str, i + 1, j); str.pop_back(); }
    if (j - 1 >= 0 && maze[i][j - 1] == 1) { str.push_back('L'); addpath(ans, maze, s, str, i, j - 1); str.pop_back(); }
    if (j + 1 < s && maze[i][j + 1] == 1) { str.push_back('R'); addpath(ans, maze, s, str, i, j + 1); str.pop_back(); }
    if (i - 1 >= 0 && maze[i - 1][j] == 1) { str.push_back('U'); addpath(ans, maze, s, str, i - 1, j); str.pop_back(); }
    maze[i][j] = 1;
}
```

- **Time Complexity:** O(4^(n^2))
  - At each cell, up to 4 choices (D, L, R, U), for n^2 cells. In the worst case (all open), the number of paths is exponential.
- **Space Complexity:** O(n^2) for the maze (visited cells), O(n) for the path string, and O(n^2) for the recursion stack in the worst case.
- **How to Analyze:**
  - For each cell, the rat can move in 4 directions, so the number of recursive calls grows rapidly. For a grid of size n x n, the upper bound is 4^(n^2), but in practice, blocked cells and visited checks reduce this.

### Example: N-Queens

- **Time Complexity:** O(N!)
  - For each row, try N columns, but choices reduce as queens are placed.
- **Space Complexity:** O(N^2) for the board, O(N) for the call stack.

---

## How to Analyze Recursion Complexity

1. **Write the Recurrence Relation:**
   - E.g., for merge sort: T(n) = 2T(n/2) + O(n)
2. **Expand the Recurrence:**
   - Substitute recursively to see the pattern.
3. **Use Master Theorem (if applicable):**
   - For T(n) = aT(n/b) + f(n), use the Master Theorem.
4. **Count the Number of Calls:**
   - For backtracking, count the number of branches at each level.
5. **Consider Stack Depth:**
   - Space is often proportional to the maximum depth of recursion.

---

## Summary Table

| Problem           | Time Complexity | Space Complexity | Notes                        |
| ----------------- | --------------- | ---------------- | ---------------------------- |
| Factorial         | O(n)            | O(n)             | Linear recursion             |
| Fibonacci (naive) | O(2^n)          | O(n)             | Exponential, avoid naive     |
| Fibonacci (DP)    | O(n)            | O(n)             | Memoization                  |
| Merge Sort        | O(n log n)      | O(n)             | Divide and conquer           |
| Quick Sort        | O(n log n)      | O(log n)         | Worst O(n^2), avg O(n log n) |
| N-Queens          | O(N!)           | O(N^2)           | Backtracking                 |

---

## Today's Example: Rat in a Maze (Day 69)

- **Problem:** [Rat in a Maze - GFG](https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1)
- **Approach:** Backtracking
- **Time Complexity:** O(4^(n^2))
  - At each cell, up to 4 choices (D, L, R, U), for n^2 cells. In the worst case (all open), the number of paths is exponential.
- **Space Complexity:** O(n^2) for the maze (visited cells), O(n) for the path string, and O(n^2) for the recursion stack in the worst case.
- **How to Analyze:**
  - For each cell, the rat can move in 4 directions, so the number of recursive calls grows rapidly. For a grid of size n x n, the upper bound is 4^(n^2), but in practice, blocked cells and visited checks reduce this.
- **Code Reference:** [`Rat_in_a_maze.cpp`](./Rat_in_a_maze.cpp)

---

## Tips

- For single recursion, count the number of calls.
- For divide-and-conquer, write the recurrence and use the Master Theorem.
- For backtracking, multiply the number of choices at each step by the depth.
- Always consider both time and space (stack, auxiliary data structures).

---
