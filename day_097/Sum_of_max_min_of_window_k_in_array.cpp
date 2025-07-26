#include <bits/stdc++.h>
using namespace std;

// link - https://www.geeksforgeeks.org/dsa/sum-minimum-maximum-elements-subarrays-size-k/

/*
Sum of minimum and maximum elements of all subarrays of size k.

Input: arr[] = {2, 5, -1, 7, -3, -1, -2}  
       k = 4 
Output: 18
Explanation: All subarrays of size 4 are : 
  {2, 5, -1, 7},   min + max = -1 + 7 = 6
  {5, -1, 7, -3},  min + max = -3 + 7 = 4
  {-1, 7, -3, -1}, min + max = -3 + 7 = 4
  {7, -3, -1, -2}, min + max = -2 + 7 = 5
Sum of all min & max = 6 + 4 + 4 + 5 = 19 
*/

class Solution
{
public:
  int maxMinSumOfSubarrays(vector<int> &arr, int k)
  {

    int s = arr.size();
    deque<int> mini, maxi;

    for (int i = 0; i < k; i++)
    {

      while (!mini.empty() && arr[mini.back()] >= arr[i])
        mini.pop_back();
      while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        maxi.pop_back();

      mini.push_back(i);
      maxi.push_back(i);
    }

    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];

    for (int i = k; i < s; i++)
    {

      // Remove elements that are out of the current window
      while (!mini.empty() && i - mini.front() >= k)
      {
        mini.pop_front();
      }
      while (!maxi.empty() && i - maxi.front() >= k)
      {
        maxi.pop_front();
      }

      // Remove elements that are smaller/larger than current element
      while (!mini.empty() && arr[mini.back()] >= arr[i])
        mini.pop_back();
      while (!maxi.empty() && arr[maxi.back()] <= arr[i])
        maxi.pop_back();

      mini.push_back(i);
      maxi.push_back(i);
      ans += arr[maxi.front()] + arr[mini.front()];
    }
    return ans;
  }
};

// Main function for testing
int main()
{
  Solution sol;

  // Test case 1
  vector<int> arr1 = {2, 5, -1, 7, -3, -1, -2};
  int k1 = 4;
  cout << "Sum of max + min for each window of size " << k1 << ": "
       << sol.maxMinSumOfSubarrays(arr1, k1) << endl;

  // Test case 2
  vector<int> arr2 = {1, 2, 3, 4, 5};
  int k2 = 3;
  cout << "Sum of max + min for each window of size " << k2 << ": "
       << sol.maxMinSumOfSubarrays(arr2, k2) << endl;

  return 0;
}