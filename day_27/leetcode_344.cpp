// reverse string
// C++ program to demonstrate the working of char arrays

// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.

 

// Example 1:

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
// Example 2:

// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]
 

// Constraints:

// 1 <= s.length <= 105
// s[i] is a printable ascii character


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//function to reverse a string that is in array form;
void reverseString(vector<char>& s) {

        // using stl 
        // reverse(s.begin(),s.end());

        // explicitely
         int i = 0 , j = s.size() -1;
     while(i<=j){
        swap(s[i++],s[j--]);
     }
    }

int main() {
    // declaring and initializing char array
    vector<char> name = {'h','e','l','l','o'};
    cout << "Your name is: ";
    for (char c : name) {
        cout << c;
    }
    cout << endl;

    reverseString(name);
    cout << "Reversed name is: ";
    for (char c : name) {
        cout << c;
    }
    cout << endl;
return 0;
}