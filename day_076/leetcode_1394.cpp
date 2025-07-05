//1394. Find Lucky Integer in an Array

//https://leetcode.com/problems/find-lucky-integer-in-an-array/

/*
Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.

Return the largest lucky integer in the array. If there is no lucky integer return -1.

 

Example 1:

Input: arr = [2,2,3,4]
Output: 2
Explanation: The only lucky number in the array is 2 because frequency[2] == 2.
Example 2:

Input: arr = [1,2,2,3,3,3]
Output: 3
Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
Example 3:

Input: arr = [2,2,2,3,3]
Output: -1
Explanation: There are no lucky numbers in the array.
 

Constraints:

1 <= arr.length <= 500
1 <= arr[i] <= 500
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;


// my approach to solve the problem but it is not the most efficient way
// I used a map to count the frequency of each integer in the array
// Function to find the largest lucky integer in an array
//time complexity: O(n)
//space complexity: O(n)
 int findLucky(vector<int>& arr) {
        map<int,int> freq;
        for(int i : arr){
            freq[i]++;
        }
        int largest_freq = -1;
        for(auto i : freq){
            if(i.first == i.second && i.second > largest_freq){
                largest_freq = i.second;
            }
        }
        return largest_freq;
    }

// Optimized approach using a single pass
// Function to find the largest lucky integer in an array
//time complexity: O(n)
//space complexity: O(1)
int findLuckyOptimized(vector<int>& arr) {
    vector<int> count(501, 0); // Since 1 <= arr[i] <= 500
    for (int num : arr) {
        count[num]++;
    }
    
    int largestLucky = -1;
    for (int i = 1; i <= 500; ++i) {
        if (count[i] == i) {
            largestLucky = max(largestLucky, i);
        }
    }
    
    return largestLucky;
}
int main() {
    vector<int> arr = {2, 2, 3, 4};
    int result = findLucky(arr);
    cout << "The largest lucky integer is: " << result << endl; // Output: 2
    // You can test with other arrays as well
    vector<int> arr2 = {1, 2, 2, 3, 3, 3};
    cout << "The largest lucky integer is: " << findLucky(arr2) << endl; // Output: 3
    vector<int> arr3 = {2, 2, 2, 3, 3};
    cout << "The largest lucky integer is: " << findLucky(arr3) << endl; // Output: -1

    // Testing the optimized function
    cout << "The largest lucky integer (optimized) is: " << findLuckyOptimized(arr) << endl; // Output: 2
    cout << "The largest lucky integer (optimized) is: " << findLuckyOptimized(arr2) << endl; // Output: 3
    cout << "The largest lucky integer (optimized) is: " << findLuckyOptimized(arr3) << endl; // Output: -1
return 0;
}