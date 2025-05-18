#include <iostream>
using namespace std;

// Question 1: Write a function to find the power of a number
// without using pow function
int power(int base, int exp)
{
  int result = 1;
  for (int i = 0; i < exp; i++)
  {
    result *= base;
  }
  return result;
}

// Question 2: Check if a number is palindrome
bool isPalindrome(int num)
{
  int original = num;
  int reversed = 0;

  while (num > 0)
  {
    reversed = reversed * 10 + num % 10;
    num /= 10;
  }

  return original == reversed;
}

int main()
{
  cout << "Power function test cases:" << endl;
  cout << "2^3 = " << power(2, 3) << endl;
  cout << "5^2 = " << power(5, 2) << endl;

  cout << "\nPalindrome test cases:" << endl;
  cout << "121 is palindrome: " << isPalindrome(121) << endl;
  cout << "123 is palindrome: " << isPalindrome(123) << endl;
  return 0;
}
