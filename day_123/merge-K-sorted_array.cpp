#include <vector>
#include <queue>
#include <utility>
using namespace std;

// Custom type for heap elements: {value, {array_index, position_in_array}}
using Node = pair<int, pair<int, int>>;

// Merge k Sorted Arrays
// Link: https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

/*
Problem Description:
Given k sorted arrays in a matrix of size k*k, merge them into a single sorted array.

Approaches:
1. Divide and Conquer (O(k²*log k)):
   - Recursively merge pairs of arrays
   - Similar to merge sort's merge process
   - Reduces number of arrays by half in each step

2. Min Heap (O(n*k*log k)):
   - Use min heap to track smallest elements
   - Each element stores value and position info
   - Always extract minimum from heap

Key Insights:
1. Min Heap Approach:
   - Need custom data structure to track position
   - Only store k elements at a time
   - Natural ordering maintained by heap

2. Divide and Conquer:
   - Reduces comparisons
   - Better cache locality
   - Easier to parallelize

Example Walk-through:
Input: k=3, arr[][]={{1,2,3},{4,5,6},{7,8,9}}

Min Heap Steps:
1. Initial heap: [1(0,0), 4(1,0), 7(2,0)]
2. Extract 1, push 2: [2(0,1), 4(1,0), 7(2,0)]
3. Extract 2, push 3: [3(0,2), 4(1,0), 7(2,0)]
4. Extract 3, no push: [4(1,0), 7(2,0)]
5. Extract 4, push 5: [5(1,1), 7(2,0)]
... continue until all elements processed

Time Complexity:
- Min Heap: O(N * log k) where N = k*k
- Divide & Conquer: O(k² * log k)

Space Complexity:
- Min Heap: O(k) for heap + O(k²) for result
- Divide & Conquer: O(k²) for result
Return type: vector<int> containing all elements in sorted order.


Examples :

Input: k = 3, arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
Output: 1 2 3 4 5 6 7 8 9
Explanation: Above test case has 3 sorted arrays of size 3, 3, 3 arr[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]. The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
Input: k = 4, arr[][]={{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}}
Output: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9
Explanation: Above test case has 4 sorted arrays of size 4, 4, 4, 4 arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4], [5, 5, 6, 6], [7, 8, 9, 9 ]]. The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9].
Expected Time Complexity: O(k2*Log(k))
Expected Auxiliary Space: O(k2)

Constraints:
1 <= k <= 100
*/

class Solution
{
public:
  // Function to merge k sorted arrays using Min Heap approach
  // Custom data type for heap elements:
  // - first: value from array
  // - second.first: row index (which array)
  // - second.second: column index (position in array)
  using Node = pair<int, pair<int, int>>;

  // Alternate Divide and Conquer approach (commented out)
  // Merges two sorted vectors into one
  //  vector<int> merge(vector<int> &v1 , vector<int> &v2){
  //     if(v1.size() == 0 ) return v2;
  //     if(v2.size() == 0 ) return v1;

  //     vector<int> v;
  //     int i = 0 , j = 0; // Pointers for two arrays

  //     while( i < v1.size() && j < v2.size()){

  //         if(v1[i] <= v2[j]){
  //             v.push_back(v1[i++]);
  //         }else{
  //             v.push_back(v2[j++]);
  //         }

  //     }

  //     while(i < v1.size()) v.push_back(v1[i++]);
  //     while(j < v2.size()) v.push_back(v2[j++]);

  //     v1 = v;

  //     return v1;

  // }
  // vector<int> mergeKArrays(vector<vector<int>> arr, int K) {

  //   while (K > 1) {
  //         int idx = 0; // new index after merging
  //         for (int i = 0; i < K; i += 2) {
  //             if (i + 1 < K) {
  //                 arr[idx++] = merge(arr[i], arr[i + 1]);
  //             } else {
  //                 arr[idx++] = arr[i]; // odd leftover
  //             }
  //         }
  //         K = idx; // reduce number of arrays
  //     }
  //     return arr[0];
  // }

  // min heap approach

  // Node type is already defined at the top of the file

  vector<int> mergeKArrays(vector<vector<int>> arr, int K)
  {
    // Create min heap to always get smallest element
    // greater<Node> makes it min heap instead of max heap
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    // Initialize heap with first element from each array
    // Only add if array is not empty
    // Store: {value, {array_index, element_index}}
    for (int i = 0; i < K; i++)
    {
      if (!arr[i].empty())
      {
        pq.push({arr[i][0], {i, 0}});
      }
    }

    // now we min heap alrady handle the sorting
    // now a made vector ds for reutrn the value

    // Result vector to store merged array
    vector<int> ans;

    // Process elements until heap is empty
    // At each step:
    // 1. Get & remove minimum element from heap
    // 2. Add it to result array
    // 3. If there are more elements in same array, add next element to heap
    while (!pq.empty())
    {
      // Get minimum element and its position
      Node top = pq.top();
      pq.pop();

      // Add minimum element to result
      ans.push_back(top.first);

      // Extract position information
      int i = top.second.first;  // Which array (row)
      int j = top.second.second; // Position in array (column)

      // If more elements exist in same array, add next element to heap
      if (j + 1 < arr[i].size())
      {
        pq.push({arr[i][j + 1], {i, j + 1}});
      }
    }

    return ans;
  }
};