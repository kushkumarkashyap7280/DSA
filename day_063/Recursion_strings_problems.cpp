// here we deal with string , int questions and use Recusion to solve them

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// function to reverse a string using recursion
// time complexity: O(n)
// space complexity: O(n) due to recursion stack

// function to check if binary of a number is palindrome or not
string reverseStr(string s, int j, int i = 0)
{
  if (i >= j)
    return s;
  swap(s[i], s[j]);
  return reverseStr(s, j - 1, i + 1); // maintain i, j order
}

string binary(long long n, string r = "")
{
  if (n == 0)
    return (r.empty() ? "0" : r); // to handle n=0 case
  return binary(n >> 1, ((n & 1) ? "1" : "0") + r);
}

bool checkPalindrome(long long N)
{
  string org = binary(N);
  string rev = reverseStr(org, org.size() - 1);
  return org == rev;
}

// function to find  a to the power n;
long long power(int a, int n, long long ans = 1)
{
  if (n == 0)
    return ans;
  ans *= a;
  return power(a, n - 1, ans);
}
//optimised to find a to the power n;
long long optimisedpower(int a , int n ,long long ans = 1){
  if(n ==0 ) return ans;
  if(n&1){
    return optimisedpower(a , n -1, ans*a);
  }else{
    return optimisedpower(a*a , n/2 ,ans);
  }
}
int main()
{
  // Reverse a string
  string s = "Hello World";
  string reversedString = reverseStr(s, s.length() - 1);
  cout << "Reversed String: " << reversedString << endl;
  // Output: Reversed String: dlroW olleH

  // Check if binary representation of a number is palindrome
  long long number = 9; // Example number
  bool isPalindrome = checkPalindrome(number);
  cout << "Is binary of " << number << " a palindrome? " << (isPalindrome ? "Yes" : "No") << endl;
  // Output: Is binary of 9 a palindrome? Yes

  // Calculate power of a number
  int base = 2, exponent = 10;
  long long result = power(base, exponent);
  cout << base << " raised to the power " << exponent << " is: " << result << endl;
  // Output: 2 raised to the power 10 is: 1024

  // Optimised power calculation
  int a = 2, n = 10;
  long long optimisedResult = optimisedpower(a, n);
  cout << a << " raised to the power " << n << " (optimised) is: " << optimisedResult << endl;
  // Output: 2 raised to the power 10 (optimised) is: 1024

  return 0;
}