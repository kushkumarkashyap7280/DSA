// 204. Count Primes

// https://leetcode.com/problems/count-primes/

/*
Given an integer n, return the number of prime numbers that are strictly less than n.



Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0


Constraints:

0 <= n <= 5 * 106
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int a)
{
  if (a == 2)
    return true;
  if (a % 2 == 0)
    return false;
  for (int i = 3; i <= sqrt(a); i += 2)
  {
    if (a % i == 0)
      return false;
  }
  return true;
}
// normal solution : (not optimized)
// time complexity: O(n * sqrt(n))
// space complexity: O(1)
int countPrimes(int n)
{
  int count = 0;
  for (int i = 2; i < n; i++)
  {
    if (isPrime(i))
      count++;
  }
  return count;
}
// optimized solution using Sieve of Eratosthenes
// time complexity: O(n log(log(n)))
// space complexity: O(n)
int countPrimes(int n)
{
  if (n <= 2)
    return 0;

  vector<bool> allPrimes(n, true);
  allPrimes[0] = allPrimes[1] = false;

  int count = 0;
  for (int i = 2; i < n; i++)
  {
    if (allPrimes[i])
    {
      count++;
      for (long long j = 1LL * i * i; j < n; j += i)
      {
        allPrimes[j] = false;
      }
    }
  }

  return count;
}

int main()
{
  int n;
  cout << "Enter a number: ";
  cin >> n;
  int result = countPrimes(n);
  cout << "Number of primes less than " << n << " is: " << result << endl;

  return 0;
}