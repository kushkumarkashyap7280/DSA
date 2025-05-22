# 2D Arrays and 2D Vectors in C++

This directory contains examples and implementations of 2D arrays and 2D vectors in C++, along with some LeetCode problems that utilize these data structures.

## 2D Arrays

A 2D array is a collection of elements arranged in a two-dimensional grid with a fixed number of rows and columns. It's essentially an "array of arrays".

### Key Characteristics of 2D Arrays:

1. **Fixed Size**: The dimensions (rows and columns) must be known at compile time or declared with constants.
2. **Contiguous Memory**: Elements are stored in contiguous memory locations.
3. **Static Memory Allocation**: Memory is allocated on the stack (unless dynamically allocated with `new`).
4. **Direct Access**: Elements can be accessed directly using row and column indices.

### Initialization Methods:

```cpp
// Method 1: Default initialization (contains garbage values)
int arr1[3][4];

// Method 2: Zero initialization
int arr2[3][4] = {0};

// Method 3: Full initialization
int arr3[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
};
```

### Finding Dimensions:

```cpp
int rows = sizeof(arr) / sizeof(arr[0]);       // number of rows
int cols = sizeof(arr[0]) / sizeof(arr[0][0]); // number of columns
```

### Common Operations:

1. **Traversal**: Using nested loops to access each element
2. **Finding max/min elements**
3. **Calculating row-wise and column-wise sums**
4. **Searching for specific elements**

### Limitations:

1. Fixed size that cannot be changed at runtime
2. Cannot have rows of different lengths
3. Passing to functions requires specifying column size

## 2D Vectors

A 2D vector is a dynamic array of dynamic arrays, implemented using the C++ Standard Template Library (STL) `vector` container.

### Key Characteristics of 2D Vectors:

1. **Dynamic Size**: Can resize at runtime
2. **Flexible Structure**: Rows can have different numbers of columns
3. **Heap Memory**: Elements are stored on the heap
4. **Rich API**: Comes with built-in methods for manipulation

### Initialization Methods:

```cpp
// Method 1: Declaration with size
vector<vector<int>> vec1(3, vector<int>(4, 0)); // 3x4 matrix initialized with 0

// Method 2: Declaration with initializer list
vector<vector<int>> vec2 = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};

// Method 3: Dynamic creation
vector<vector<int>> vec3(rows, vector<int>(cols));
```

### Vector Methods:

1. **Size Operations**: `size()`, `resize()`, `capacity()`, `reserve()`
2. **Element Addition/Removal**: `push_back()`, `pop_back()`, `clear()`
3. **Element Access**: `[]`, `at()`, `front()`, `back()`
4. **Status Checking**: `empty()`

### Advantages over 2D Arrays:

1. Dynamic size - can grow or shrink at runtime
2. Each row can have a different number of columns
3. Rich set of built-in methods
4. Easier to pass to functions (no need to specify column size)

### Disadvantages compared to 2D Arrays:

1. Slightly slower due to dynamic memory allocation
2. Higher memory overhead
3. Not stored in contiguous memory (vector of vectors)

## When to Use Which?

- **Use 2D Arrays when**:
  - Size is known at compile time and won't change
  - Performance is critical
  - Memory efficiency is important

- **Use 2D Vectors when**:
  - Size is unknown at compile time or needs to change
  - Rows may have different lengths
  - Ease of use is more important than performance
  - Need to pass the structure to functions easily

## LeetCode Problems in this Directory

This directory contains solutions to the following LeetCode problems that utilize 2D arrays/vectors:

### Problem 1: Search a 2D Matrix [LeetCode 74](https://leetcode.com/problems/search-a-2d-matrix/)

#### Problem Description

You are given an m x n integer matrix with the following two properties:
- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in the matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

#### Examples

```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
```

#### Approaches

##### 1. Two Binary Searches Approach (Not Optimal)
- **Time Complexity**: O(log(m) + log(n))
- **Space Complexity**: O(1)
- **Algorithm**:
  1. First binary search to find the row where target might be located
  2. Second binary search within that row to find the target

```cpp
int findrow(vector<vector<int>> &matrix, int target, int r, int c) {
  if (target < matrix[0][0] || target > matrix[r - 1][c - 1])
    return -1;
  int i = 0, j = r - 1;
  while (i <= j) {
    int m = i + (j - i) / 2;
    if (target >= matrix[m][0] && target <= matrix[m][c - 1]) {
      return m;
    } else if (target < matrix[m][0]) {
      j = m - 1;
    } else {
      i = m + 1;
    }
  }
  return -1;
}

bool searchMatrix(vector<vector<int>> &matrix, int target) {
  int r = matrix.size();
  int c = matrix[0].size();
  int result = findrow(matrix, target, r, c);
  if (result == -1)
    return false;
  int i = 0, j = c - 1;
  while (i <= j) {
    int m = i + (j - i) / 2;
    if (target == matrix[result][m]) {
      return true;
    } else if (target < matrix[result][m]) {
      j = m - 1;
    } else {
      i = m + 1;
    }
  }
  return false;
}
```

##### 2. Single Binary Search (Optimal)
- **Time Complexity**: O(log(m*n))
- **Space Complexity**: O(1)
- **Algorithm**:
  1. Treat the 2D matrix as a 1D sorted array
  2. Perform a single binary search
  3. Map the middle index to the corresponding row and column

```cpp
bool searchMatrix(vector<vector<int>> &matrix, int target) {
  int r = matrix.size();
  int c = matrix[0].size();

  if (target < matrix[0][0] || target > matrix[r - 1][c - 1])
    return false;
  int p = 0, q = r * c - 1;
  while (p <= q) {
    int m = p + (q - p) / 2;
    int row = m / c;
    int col = m % c;
    if (target == matrix[row][col]) {
      return true;
    } else if (target < matrix[row][col]) {
      q = m - 1;
    } else {
      p = m + 1;
    }
  }
  return false;
}
```

#### Key Points
1. **Matrix Properties**: The problem leverages the special properties of the matrix (sorted rows and columns with specific relationships)
2. **Binary Search**: The optimal solution uses a single binary search by treating the 2D matrix as a 1D sorted array
3. **Index Mapping**: The key insight is mapping a 1D index to 2D coordinates using division and modulo operations

### Problem 2: Transpose Matrix [LeetCode 867](https://leetcode.com/problems/transpose-matrix/)

#### Problem Description

Given a 2D integer array `matrix`, return the transpose of the matrix.

The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

#### Examples

```
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]

Input: matrix = [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
```

#### Approach
- **Time Complexity**: O(m*n)
- **Space Complexity**: O(m*n)
- **Algorithm**:
  1. Create a new matrix with dimensions swapped (rows become columns, columns become rows)
  2. Iterate through the original matrix
  3. For each element at position (i,j), place it at position (j,i) in the new matrix

```cpp
vector<vector<int>> transpose(vector<vector<int>> &matrix) {
  int rows = matrix.size();
  int cols = matrix[0].size();
  vector<vector<int>> ans(cols, vector<int>(rows, 0));
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      ans[j][i] = matrix[i][j];
    }
  }
  return ans;
}
```

#### Key Points
1. **Matrix Dimensions**: The transpose of an m×n matrix has dimensions n×m
2. **New Matrix Creation**: We must create a new matrix with swapped dimensions
3. **Element Mapping**: Each element at (i,j) in the original matrix maps to (j,i) in the transpose
4. **Space Requirement**: For non-square matrices, a new matrix is required as dimensions change

### Problem 3: Convert 1D Array Into 2D Array [LeetCode 2022](https://leetcode.com/problems/convert-1d-array-into-2d-array/)

#### Problem Description

You are given a 0-indexed 1-dimensional (1D) integer array `original`, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with m rows and n columns using all the elements from original.

The elements from indices 0 to n - 1 (inclusive) of original should form the first row of the constructed 2D array, the elements from indices n to 2 * n - 1 (inclusive) should form the second row of the constructed 2D array, and so on.

Return an m x n 2D array constructed according to the above procedure, or an empty 2D array if it is impossible.

#### Examples

```
Input: original = [1,2,3,4], m = 2, n = 2
Output: [[1,2],[3,4]]

Input: original = [1,2,3], m = 1, n = 3
Output: [[1,2,3]]

Input: original = [1,2], m = 1, n = 1
Output: []
```

#### Approach
- **Time Complexity**: O(m*n)
- **Space Complexity**: O(m*n)
- **Algorithm**:
  1. Check if the size of the original array equals m*n; if not, return empty array
  2. Create a new 2D array with m rows and n columns
  3. Fill the 2D array row by row using elements from the original array

```cpp
vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
  if(original.size() != m*n) return {}; // check if the size of original is equal to m*n
  vector<vector<int>> two_d(m, vector<int>(n, 0));
  int c = 0;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      two_d[i][j] = original[c++];
    }
  }
  return two_d;
}
```

#### Key Points
1. **Size Validation**: The total number of elements in the 1D array must equal m*n
2. **Row-Major Order**: Elements are filled row by row in the 2D array
3. **Linear Traversal**: A single counter is used to track position in the original array
4. **Edge Cases**: Returns an empty array if the conversion is impossible
