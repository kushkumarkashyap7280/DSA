//59. Spiral Matrix II

//https://leetcode.com/problems/spiral-matrix-ii/

/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to generate a spiral matrix of size n x n
// Time Complexity: O(n^2) where n is the size of the matrix
// Space Complexity: O(n^2) for storing the matrix
vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n , vector<int>(n,0));
         int count = 1;
        int left = 0;
        int right = n -1;
        int top = 0;
        int bottom = n -1;
        while(count <= n*n){
            for(int i = left ; i <= right; i++){
                res[top][i] =count++;
            }
            top++;
             for(int i = top ; i <= bottom; i++){
                res[i][right] =count++;
            }
            right--;
             for(int i = right ; i >= left; i--){
                res[bottom][i]= count++;
            }
            bottom--;
             for(int i = bottom ; i >= top; i--){
                res[i][left] = count ++;
            }
            left++;
        }
        return res;
    }
int main() {
    int n;
    cout << "Enter the size of the matrix (n): ";
    cin >> n;

    vector<vector<int>> result = generateMatrix(n);

    cout << "Spiral Matrix of size " << n << "x" << n << ":\n";
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
return 0;
}