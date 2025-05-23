# Day 33: Print Like A Wave

### Problem Links : [Naukri Code360](https://www.naukri.com/code360/problem-details/print-like-a-wave_893268)

## Problem: Wave Print of 2D Array

Given a 2D array, print its elements in a wave pattern. The wave pattern follows these rules:

- Print first column from top to bottom
- Print second column from bottom to top
- Print third column from top to bottom
- And so on...

### Approach

1. **Wave Pattern Logic**:

   - For even-numbered columns (0, 2, 4...), traverse from top to bottom
   - For odd-numbered columns (1, 3, 5...), traverse from bottom to top

2. **Implementation Steps**:
   - Create a result vector to store the wave pattern
   - Iterate through columns (0 to m-1)
   - For each column:
     - If column number is even: traverse top to bottom
     - If column number is odd: traverse bottom to top
   - Add elements to result vector during traversal

### Complexity Analysis

- **Time Complexity**: O(n×m) where n is number of rows and m is number of columns
- **Space Complexity**: O(n×m) for storing the result

### Example

Input:

```
1 2 3 4
5 6 7 8
9 10 11 12
```

Output: `1 5 9 10 6 2 3 7 11 12 8 4`

### Additional Notes

- This is a common interview problem that tests understanding of 2D array traversal
- Similar variations include spiral matrix traversal and zigzag traversal
- Key is to handle the direction change at column boundaries

### Code Implementation

```cpp
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols) {
    vector<int> result;
    for(int j = 0; j < mCols; j++) {
        if(j % 2 == 0) {
            // Top to bottom for even columns
            for(int i = 0; i < nRows; i++)
                result.push_back(arr[i][j]);
        } else {
            // Bottom to top for odd columns
            for(int i = nRows-1; i >= 0; i--)
                result.push_back(arr[i][j]);
        }
    }
    return result;
}
```
