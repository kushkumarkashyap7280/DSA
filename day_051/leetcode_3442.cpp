//3442. Maximum Difference Between Even and Odd Frequency I

//https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/

/*
You are given a string s consisting of lowercase English letters.

Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:

a1 has an odd frequency in the string.
a2 has an even frequency in the string.
Return this maximum difference.

 

Example 1:

Input: s = "aaaaabbc"

Output: 3

Explanation:

The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
The maximum difference is 5 - 2 = 3.
Example 2:

Input: s = "abcabcab"

Output: 1

Explanation:

The character 'a' has an odd frequency of 3, and 'c' has an even frequency of 2.
The maximum difference is 3 - 2 = 1.
 

Constraints:

3 <= s.length <= 100
s consists only of lowercase English letters.
s contains at least one character with an odd frequency and one with an even frequency.
*/

#include <iostream>
#include <string>
using namespace std;

// Function to calculate the maximum difference between odd and even frequencies
//time complexity: O(n), where n is the length of the string
//space complexity: O(1), since we are using a fixed-size frequency array of size 26
int maxDifference(string s) {
    int freq[26] = {0}; // Frequency array for 26 lowercase letters

    // Count the frequency of each character
    for (char c : s) {
        freq[c - 'a']++;
    }

    int maxOdd = 0; // Maximum odd frequency
    int minEven = INT_MAX; // Minimum even frequency

    // Iterate through the frequency array to find maxOdd and minEven
    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) { // Odd frequency
            maxOdd = max(maxOdd, freq[i]);
        } else if (freq[i] > 0) { // Even frequency
            minEven = min(minEven, freq[i]);
        }
    }

    return maxOdd - minEven; // Return the maximum difference
}
int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    int result = maxDifference(s);
    cout << "Maximum difference between odd and even frequencies: " << result << endl;
return 0;
}