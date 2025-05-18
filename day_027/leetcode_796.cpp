// rotate string

// Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

// A shift on s consists of moving the leftmost character of s to the rightmost position.

// For example, if s = "abcde", then it will be "bcdea" after one shift.
 

// Example 1:

// Input: s = "abcde", goal = "cdeab"
// Output: true
// Example 2:

// Input: s = "abcde", goal = "abced"
// Output: false
 

// Constraints:

// 1 <= s.length, goal.length <= 100
// s and goal consist of lowercase English letters.

#include <iostream>
#include <string>
#include <algorithm> // for reverse
using namespace std;

// first approach :
  // bool rotate(string s , int i , string goal){
  //       string k = s;
  //       reverse(k.begin(),k.end());
  //        reverse(k.begin(),k.begin()+i);
  //          reverse(k.begin()+i,k.end());
  //       return k ==  goal;
       
  //   }
  //   bool rotateString(string s, string goal) {
  //       for(int i = 0 ; i< s.size(); i++){
  //        if(rotate(s, i , goal)) return true;
  //       }
  //       return false;
  //   }

// Time complexity : O(n^2)
// Space complexity : O(n)
    ////////////////////////////////////////////

// second approach :
bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        if(m != n){
            return false;
        }

        string temp = s + s;
        return temp.find(goal) != string::npos;
    };
// Time complexity : O(n)
// Space complexity : O(n)

int main() {
    string s = "abcde";
    string goal = "cdeab";

    if (rotateString(s, goal)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

return 0;
}