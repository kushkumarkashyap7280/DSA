//3330. Find the Original Typed String I

//https://leetcode.com/problems/find-the-original-typed-string-i/

/*
Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.

Although Alice tried to focus on her typing, she is aware that she may still have done this at most once.

You are given a string word, which represents the final output displayed on Alice's screen.

Return the total number of possible original strings that Alice might have intended to type.

 

Example 1:

Input: word = "abbcccc"

Output: 5

Explanation:

The possible strings are: "abbcccc", "abbccc", "abbcc", "abbc", and "abcccc".

Example 2:

Input: word = "abcd"

Output: 1

Explanation:

The only possible string is "abcd".

Example 3:

Input: word = "aaaa"

Output: 4

 

Constraints:

1 <= word.length <= 100
word consists only of lowercase English letters.
*/

#include <iostream>
#include <string>
using namespace std;

// Function to count the number of possible original strings
//time complexity: O(n), where n is the length of the input string
//space complexity: O(1), since we are using a constant amount of extra space
int countOriginalStrings(const string& word) {
    int count = 1; // Start with 1 for the original string itself
    int n = word.length();

    for (int i = 0; i < n; ) {
        int j = i;
        // Count the length of the current character sequence
        while (j < n && word[j] == word[i]) {
            j++;
        }
        // If the sequence length is greater than 1, it can be reduced
        if (j - i > 1) {
            count += j - i - 1; // Add the number of possible reductions
        }
        i = j; // Move to the next character sequence
    }

    return count;
}
int main() {
    string word;
    cout << "Enter the typed string: ";
    cin >> word;

    int result = countOriginalStrings(word);
    cout << "Total number of possible original strings: " << result << endl;
return 0;
}