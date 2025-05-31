// 28. Find the Index of the First Occurrence in a String
// LeetCode problem link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

/*
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
 

Constraints:

1 <= haystack.length, needle.length <= 104
haystack and needle consist of only lowercase English characters.
*/
#include <iostream>
#include <string>
using namespace std;

// Function to find the index of the first occurrence of needle in haystack
//time complexity: O(n*m) where n is the length of haystack and m is the length of needle
//space complexity: O(1) as we are not using any extra space
int strStr1(string haystack, string needle) {
    if (needle.empty()) return 0; // If needle is empty, return 0
    int haystackLength = haystack.length();
    int needleLength = needle.length();
    
    for (int i = 0; i <= haystackLength - needleLength; ++i) {
        if (haystack.substr(i, needleLength) == needle) {
            return i; // Return the index of the first occurrence
        }
    }
    
    return -1; // If needle is not found, return -1
}

// function to find the index of the first occurrence of needle in haystack using string::find
// time complexity: O(n) where n is the length of haystack
// space complexity: O(1) as we are not using any extra space
 int strStr2(string haystack, string needle) {
      if(haystack.find(needle)!= string::npos){
        return haystack.find(needle);
      }else{
        return -1;
      }
    }
int main() {
    string haystack = "sadbutsad";
    string needle = "sad";
    
    int index = strStr1(haystack, needle);
    cout << "The index of the first occurrence of '" << needle << "' in '" << haystack << "' is: " << index << endl;

    haystack = "leetcode";
    needle = "leeto";
    
    index = strStr2(haystack, needle);
    cout << "The index of the first occurrence of '" << needle << "' in '" << haystack << "' is: " << index << endl;
return 0;
}