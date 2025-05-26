#include <iostream>
using namespace std;

// Approach 1: Using Binomial Coefficient
// Time Complexity: O(n)
// Space Complexity: O(1)
long long binomialCoeff(int n, int k)
{
  long long res = 1;

  if (k > n - k)
    k = n - k; // Take advantage of symmetry

  for (int i = 0; i < k; ++i)
  {
    res *= (n - i);
    res /= (i + 1);
  }

  return res;
}

long long findCatalanUsingBinomial(int n)
{
  return binomialCoeff(2 * n, n) / (n + 1);
}

// Approach 2: Using Factorial
// Time Complexity: O(n) but with larger constant factor due to factorial calculations
// Space Complexity: O(n) due to recursive stack
long long factorialof(int n)
{
  if (n == 0 || n == 1)
    return 1;
  return (long long)n * factorialof(n - 1);
}

long long findCatalanUsingFactorial(int n)
{
  if (n == 0 || n == 1)
    return 1;

  return factorialof(2 * n) / (factorialof(n + 1) * factorialof(n));
}

int main()
{
  int n;
  cout << "Enter n to find nth Catalan number: ";
  cin >> n;

  cout << "Using Binomial Coefficient approach: " << findCatalanUsingBinomial(n) << endl;
  cout << "Using Factorial approach: " << findCatalanUsingFactorial(n) << endl;

  return 0;
}
