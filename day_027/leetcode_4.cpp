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


// Function to find the median of two sorted arrays it is a brute force approach

// approach 1 :
//  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         double ans ;
//         int f1 = nums1.size();
//         int f2 = nums2.size();
//         int t = f1 + f2;
//         vector <int> sorted(t);
//         int i = 0 , j = 0, k = 0;
//         while( i < f1 && j < f2 ){
//             if(nums1[i]> nums2[j] ){
//                 sorted[k++]=nums2[j++];
//             }else if(nums1[i] <= nums2[j]){
//                 sorted[k++]=nums1[i++];
//             }
//         }

//         if(i < f1){
//             while(i < f1){
//                   sorted[k++]=nums1[i++];
//             }
//         }
//           if(j< f2){
//             while(j < f2){
//                   sorted[k++]=nums2[j++];
//             }
//         }

//         if(t%2==0){
//            ans =  ((sorted[(k/2)-1] + sorted[k/2])/2.0);
//         }else{
//             ans = sorted[(k/2)];
//         }

//      return ans;
        
//     };
// Time complexity : O(m+n)
// Space complexity : O(n)

// approach 2 : (optimised)
// Binary search
// 1. Find the median of the two sorted arrays using binary search.
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // Ensure nums1 is the smaller array
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int n1 = nums1.size();
    int n2 = nums2.size();

    int low = 0, high = n1;

    while (low <= high) {
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

        int right1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

        if (left1 <= right2 && left2 <= right1) {
            if ((n1 + n2) % 2 == 0) {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            } else {
                return max(left1, left2);
            }
        } else if (left1 > right2) {
            high = cut1 - 1;
        } else {
            low = cut1 + 1;
        }
    }

    return 0.0; // Should never reach here if input is valid
}
// Time complexity : O(log(min(m,n)))
// Space complexity : O(1)

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