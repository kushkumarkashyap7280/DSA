//3606. Coupon Code Validator

//https://leetcode.com/problems/coupon-code-validator/

/*
You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:

code[i]: a string representing the coupon identifier.
businessLine[i]: a string denoting the business category of the coupon.
isActive[i]: a boolean indicating whether the coupon is currently active.
A coupon is considered valid if all of the following conditions hold:

code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
isActive[i] is true.
Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.

 

Example 1:

Input: code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]

Output: ["PHARMA5","SAVE20"]

Explanation:

First coupon is valid.
Second coupon has empty code (invalid).
Third coupon is valid.
Fourth coupon has special character @ (invalid).
Example 2:

Input: code = ["GROCERY15","ELECTRONICS_50","DISCOUNT10"], businessLine = ["grocery","electronics","invalid"], isActive = [false,true,true]

Output: ["ELECTRONICS_50"]

Explanation:

First coupon is inactive (invalid).
Second coupon is valid.
Third coupon has invalid business line (invalid).
 

Constraints:

n == code.length == businessLine.length == isActive.length
1 <= n <= 100
0 <= code[i].length, businessLine[i].length <= 100
code[i] and businessLine[i] consist of printable ASCII characters.
isActive[i] is either true or false.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// ✨ Solution
// ✨ 1. Check if the coupon is valid
// ✨ 2. Check if the coupon is active
// ✨ 3. Check if the coupon is in the correct business line
// ✨ 4. Check if the coupon code is valid
// ✨ 5. Sort the coupons
// ✨ 6. Return the valid coupons

// ✨ Time Complexity
// time complexity: O(n·m + k log k)
//where n is the number of coupons, m is the maximum length of a coupon code, and k is the number of valid coupons
// space complexity: O(n·m)
//where n is the number of coupons, and m is the maximum length of a coupon code

class Solution {
    string base = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_";

public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> elect, groc, pharma, rest;

        for (int i = 0; i < isActive.size(); i++) {
            if (!isActive[i]) continue;

            if (businessLine[i] == "electronics" ||
                businessLine[i] == "grocery" ||
                businessLine[i] == "pharmacy" ||
                businessLine[i] == "restaurant") {

                if (code[i].empty()) continue;

                bool notvalid = false;
                for (char c : code[i]) {
                    if (base.find(c) == string::npos) {
                        notvalid = true;
                        break;
                    }
                }

                if (!notvalid) {
                    if (businessLine[i] == "electronics") {
                        elect.push_back(code[i]);
                    } else if (businessLine[i] == "grocery") {
                        groc.push_back(code[i]);
                    } else if (businessLine[i] == "pharmacy") {
                        pharma.push_back(code[i]);
                    } else if (businessLine[i] == "restaurant") {
                        rest.push_back(code[i]);
                    }
                }
            }
        }

        // ✨ Sort each category
        sort(elect.begin(), elect.end());
        sort(groc.begin(), groc.end());
        sort(pharma.begin(), pharma.end());
        sort(rest.begin(), rest.end());

        vector<string> ans;
        ans.insert(ans.end(), elect.begin(), elect.end());
        ans.insert(ans.end(), groc.begin(), groc.end());
        ans.insert(ans.end(), pharma.begin(), pharma.end());
        ans.insert(ans.end(), rest.begin(), rest.end());

        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> code = {"SAVE20","","PHARMA5","SAVE@20"};
    vector<string> businessLine = {"restaurant","grocery","pharmacy","restaurant"};
    vector<bool> isActive = {true,true,true,true};
    vector<string> ans = sol.validateCoupons(code, businessLine, isActive);
    for (string s : ans) {
        cout << s << " ";
    }
    // output: PHARMA5 SAVE20
}