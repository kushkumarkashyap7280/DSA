// Kth Smallest


// link - https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1



/*
Given an array arr[] and an integer k where k is smaller than the size of the array, your task is to find the kth smallest element in the given array.

Follow up: Don't solve it using the inbuilt sort function.

Examples :

Input: arr[] = [7, 10, 4, 3, 20, 15], k = 3
Output: 7
Explanation: 3rd smallest element in the given array is 7.
Input: arr[] = [2, 3, 1, 20, 15], k = 4 
Output: 15
Explanation: 4th smallest element in the given array is 15.
Constraints:
1 <= arr.size <= 106
1<= arr[i] <= 106
1 <= k <= n
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// User function template for C++

class Solution {

  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
       
       priority_queue<int> pq;
       for(int i = 0 ; i < k ; i++){
           pq.push(arr[i]);
       }
       
       for(int i = k ; i < arr.size() ; i++){
           if(arr[i] < pq.top()){
               pq.pop();
               pq.push(arr[i]);
           }
       }
        
        return pq.top();
    }
};


int main() {
    vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3;
    Solution sol;
    cout << sol.kthSmallest(arr, k) << endl;
    return 0;
}