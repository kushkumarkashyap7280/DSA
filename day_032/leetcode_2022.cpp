//2022. Convert 1D Array Into 2D Array

// You are given a 0-indexed 1-dimensional (1D) integer array original, and two integers, m and n. You are tasked with creating a 2-dimensional (2D) array with  m rows and n columns using all the elements from original.

// The elements from indices 0 to n - 1 (inclusive) of original should form the first row of the constructed 2D array, the elements from indices n to 2 * n - 1 (inclusive) should form the second row of the constructed 2D array, and so on.

// Return an m x n 2D array constructed according to the above procedure, or an empty 2D array if it is impossible.

 

// Example 1:


// Input: original = [1,2,3,4], m = 2, n = 2
// Output: [[1,2],[3,4]]
// Explanation: The constructed 2D array should contain 2 rows and 2 columns.
// The first group of n=2 elements in original, [1,2], becomes the first row in the constructed 2D array.
// The second group of n=2 elements in original, [3,4], becomes the second row in the constructed 2D array.
// Example 2:

// Input: original = [1,2,3], m = 1, n = 3
// Output: [[1,2,3]]
// Explanation: The constructed 2D array should contain 1 row and 3 columns.
// Put all three elements in original into the first row of the constructed 2D array.
// Example 3:

// Input: original = [1,2], m = 1, n = 1
// Output: []
// Explanation: There are 2 elements in original.
// It is impossible to fit 2 elements in a 1x1 2D array, so return an empty 2D array.
 

// Constraints:

// 1 <= original.length <= 5 * 104
// 1 <= original[i] <= 105
// 1 <= m, n <= 4 * 104


#include <iostream>
#include <vector>
using namespace std;

// my solution

// Time Complexity: O(n)
// Space Complexity: O(n)
 vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size() != m*n) return {}; // check if the size of original is equal to m*n
        vector<vector<int>> two_d(m , vector<int>(n ,0));
         int c = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j =0 ; j< n ; j++){
                two_d[i][j] = original[c++];
            }
        }
        return two_d;
    }
int main() {
    vector<int> original = {1, 2, 3, 4};
    int m = 2;
    int n = 2;

    vector<vector<int>> result = construct2DArray(original, m, n);

    // Print the result
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}