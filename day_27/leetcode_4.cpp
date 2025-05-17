// Median of Two Sorted Arrays

// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -106 <= nums1[i], nums2[i] <= 106


#include <iostream>
#include <vector>
using namespace std;

// Function to find the median of two sorted arrays
 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans ;
        int f1 = nums1.size();
        int f2 = nums2.size();
        int t = f1 + f2;
        vector <int> sorted(t);
        int i = 0 , j = 0, k = 0;
        while( i < f1 && j < f2 ){
            if(nums1[i]> nums2[j] ){
                sorted[k++]=nums2[j++];
            }else if(nums1[i] <= nums2[j]){
                sorted[k++]=nums1[i++];
            }
        }

        if(i < f1){
            while(i < f1){
                  sorted[k++]=nums1[i++];
            }
        }
          if(j< f2){
            while(j < f2){
                  sorted[k++]=nums2[j++];
            }
        }

        if(t%2==0){
           ans =  ((sorted[(k/2)-1] + sorted[k/2])/2.0);
        }else{
            ans = sorted[(k/2)];
        }

     return ans;
        
    };
// Time complexity : O(m+n)
// Space complexity : O(n)
int main() {
 // example usage
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl; // Output: 2.00000

    // Test with another example
    vector<int> nums3 = {1, 2};
    vector<int> nums4 = {3, 4};
    median = findMedianSortedArrays(nums3, nums4);
    cout << "Median: " << median << endl; // Output: 2.50000
return 0;
}