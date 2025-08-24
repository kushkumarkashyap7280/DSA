#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// K-th Largest Sum Contiguous Subarray
// Link: https://www.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

/*
Problem Description:
Given an array arr[] of size n, find the k-th largest sum among all possible contiguous subarrays.

Time Complexity Analysis:
1. Brute Force: O(n^2 log(n^2))
   - Generate all subarrays: O(n^2)
   - Sort sums: O(n^2 log(n^2))
   - Space: O(n^2)

2. Optimized (Min Heap): O(n^2 log k)
   - Generate subarrays: O(n^2)
   - Maintain k-sized heap: O(log k)
   - Space: O(k)

Key Insights:
1. Total number of contiguous subarrays: n*(n+1)/2
2. Min heap more efficient than sorting when k << n^2
3. Only need to store k largest sums at any time
4. Can optimize space by using min heap of size k

Example Walk-through:
arr = [3, 2, 1], k = 2

Step 1: Generate all subarray sums:
- [3] = 3
- [3,2] = 5
- [3,2,1] = 6
- [2] = 2
- [2,1] = 3
- [1] = 1

Step 2: Using min heap of size k=2:
1. Push 3: heap=[3]
2. Push 5: heap=[3,5]
3. Push 6: heap=[5,6] (pop 3)
4. Push 2: no change (2 < 5)
5. Push 3: no change (3 < 5)
6. Push 1: no change (1 < 5)

Result: Second largest (k=2) is 5

Examples:

Input: arr[] = [3, 2, 1], k = 2
Output: 5
Explanation: The different subarray sums we can get from the array are = [6, 5, 3, 2, 1]. Where 5 is the 2nd largest.
Input: arr[] = [2, 6, 4, 1], k = 3
Output: 11
Explanation: The different subarray sums we can get from the arrayare = [13, 12, 11, 10, 8, 6, 5, 4, 2, 1]. Where 11 is the 3rd largest.
Constraints:
1 <= arr.size() <= 1000
1 <= k <= (n*(n+1))/2
-105 <= arr[i] <= 10
*/

// User function Template for C++

class Solution
{
public:
    // brute force approach :

    // int kthLargest(vector<int> &arr, int k) {
    //   vector<int> sums;

    //   for(int i = 0; i < arr.size(); i++){
    //       int sum = 0;
    //       for(int j = i ; j < arr.size(); j++){
    //           sum += arr[j];
    //           sums.push_back(sum);
    //       }
    //   }

    //   sort(sums.begin() , sums.end());

    //   return sums[sums.size()  - k];
    // }

    // min heap
    int kthLargest(vector<int> &arr, int k)
    {

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < arr.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < arr.size(); j++)
            {
                sum += arr[j];

                if (pq.size() < k)
                {
                    pq.push(sum);
                }
                else
                {
                    if (pq.top() < sum)
                    {
                        pq.pop();
                        pq.push(sum);
                    }
                }
            }
        }

        return pq.top();
    }
};