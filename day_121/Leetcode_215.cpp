//215. Kth Largest Element in an Array

// link - https://leetcode.com/problems/kth-largest-element-in-an-array/


/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 

Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
 

Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
 


*/

// algo say :

// step 1 :  make a min heap of size k
// step 2 :  then iterate over the rest of the elements and if the element is greater than the top of the min heap
// automatically top will become kth largest 

// time complexity : O(n log k)
//space comeplxity : o(k);


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
           priority_queue<int, vector<int>, greater<int>> pq;
       for(int i = 0 ; i < k ; i++){
           pq.push(nums[i]);
       }
       
       for(int i = k ; i < nums.size() ; i++){
           if(nums[i] > pq.top()){
               pq.pop();
               pq.push(nums[i]);
           }
       }
        
        return pq.top();
    }
};


int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    Solution sol;
    cout << sol.findKthLargest(nums, k) << endl;
    return 0;
}