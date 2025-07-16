// the celebrity problem

// link- https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

/*
A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix mat[][] (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

Note: Follow 0-based indexing.

Examples:

Input: mat[][] = [[1, 1, 0], [0, 1, 0], [0, 1, 1]]
Output: 1
Explanation: 0th and 2nd person both know 1st person. Therefore, 1 is the celebrity person.
Input: mat[][] = [[1, 1], [1, 1]]
Output: -1
Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.
Input: mat[][] = [[1]]
Output: 0
Constraints:
1 <= mat.size()<= 1000
0 <= mat[i][j]<= 1
mat[i][i] == 1
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// brute force approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
int celebrityBruteForce(vector<vector<int>> &mat)
{
  for (int i = 0; i < mat.size(); i++)
  {
    bool isCelebrity = true;
    for (int j = 0; j < mat.size(); j++)
    {
      if (i == j)
      {
        continue;
      }
      if (mat[j][i] != 1)
      {
        isCelebrity = false;
        break;
      }
    }
    if (!isCelebrity)
      continue;
    for (int j = 0; j < mat[i].size(); j++)
    {
      if (i == j)
      {
        continue;
      }
      if (mat[i][j] == 1)
      {
        isCelebrity = false;
        break;
      }
    }
    if (!isCelebrity)
      continue;
    return i;
  }
  return -1;
}

// // optimal approach
// // Time Complexity: O(n)
// // Space Complexity: O(n)
// int celebrity(vector<vector<int>> &mat)
// {
//   int n = mat.size();
//   stack<int> ans;
//   // push all person
//   for (int i = 0; i < n; i++)
//   {
//     ans.push(i);
//   }
//   while (ans.size() > 1)
//   {
//     int person1 = ans.top();
//     ans.pop();
//     int person2 = ans.top();
//     ans.pop();
//     if (mat[person1][person2] != 1)
//     {
//       ans.push(person1);
//     }
//     else
//     {
//       ans.push(person2);
//     }
//   }
//   if (ans.empty())
//     return -1;
//   int candidate = ans.top();
//   // verify candidate
//   for (int i = 0; i < n; i++)
//   {
//     if (i != candidate)
//     {
//       if (mat[candidate][i] == 1 || mat[i][candidate] == 0)
//       {
//         return -1;
//       }
//     }
//   }
//   return candidate;
// }


// most optimal 
// time complexity O(n);
// space complexity O(1);
int celebrity(vector<vector<int>>& mat) {
  int n = mat.size();
  int candidate = 0;

  // Step 1: Find candidate
  for (int i = 1; i < n; i++) {
      if (mat[candidate][i] == 1) {
          candidate = i;
      }
  }

  // Step 2: Verify candidate
  for (int i = 0; i < n; i++) {
      if (i != candidate) {
          if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
              return -1;
          }
      }
  }

  return candidate;
}


int main()
{
  // Example 1
  vector<vector<int>> mat1 = {{1, 1, 0}, {0, 1, 0}, {0, 1, 1}};
  cout << "Brute Force: Celebrity index (mat1): " << celebrityBruteForce(mat1) << endl;
  cout << "Optimal: Celebrity index (mat1): " << celebrity(mat1) << endl;

  // Example 2
  vector<vector<int>> mat2 = {{1, 1}, {1, 1}};
  cout << "Brute Force: Celebrity index (mat2): " << celebrityBruteForce(mat2) << endl;
  cout << "Optimal: Celebrity index (mat2): " << celebrity(mat2) << endl;

  // Example 3
  vector<vector<int>> mat3 = {{1}};
  cout << "Brute Force: Celebrity index (mat3): " << celebrityBruteForce(mat3) << endl;
  cout << "Optimal: Celebrity index (mat3): " << celebrity(mat3) << endl;

  return 0;
}
