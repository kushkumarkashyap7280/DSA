// Regular sieve of Eratosthenes vs Segmented Sieve
// so , the basic idea of the segmented sieve is to divide the range into smaller segments and apply the sieve of Eratosthenes on each segment.

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> simpleSieve(int limit)
{
  vector<bool> isPrime(limit + 1, true);
  vector<int> primes;
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i <= limit; ++i)
  {
    if (isPrime[i])
    {
      primes.push_back(i);
      for (int j = i * i; j <= limit; j += i)
        isPrime[j] = false;
    }
  }
  return primes;
}

void segmentedSieve(long long L, long long R)
{
  // Handle small numbers separately  if (L <= 2)
  {
    if (L <= 2 && 2 <= R)
      cout << "2 ";
    L = std::max<long long>(3LL, L); // Explicitly specify long long type
  }

  // If L is even, make it odd as even numbers > 2 are not prime
  if (L % 2 == 0)
    L++;

  int limit = sqrt(R);
  vector<int> primes = simpleSieve(limit);

  int size = R - L + 1;
  vector<bool> isPrime(size, true);

  // Mark non-prime numbers in the current segment
  for (int p : primes)
  { // Find the first multiple of p in the range [L, R]
    long long start = std::max<long long>(static_cast<long long>(p) * p, ((L + p - 1) / p) * p);
    // If start is even and not p itself, move to next odd multiple
    if (start % 2 == 0 && start != p * p)
      start += p;

    // Mark multiples of p as non-prime
    for (long long j = start; j <= R; j += 2 * p)
    {
      isPrime[(j - L)] = false;
    }
  }

  // Print prime numbers in the range
  for (long long i = 0; i < size; i += 2)
  { // Increment by 2 as we only check odd numbers
    if (isPrime[i] && (i + L) > 1)
    {
      cout << i + L << " ";
    }
  }
}

int main()
{
  long long L, R;
  cout << "Enter the range (L R): ";
  cin >> L >> R;

  if (L > R || L < 0 || R < 0)
  {
    cout << "Invalid range!" << endl;
    return 1;
  }

  cout << "Prime numbers in the range [" << L << ", " << R << "] are: ";
  segmentedSieve(L, R);
  cout << endl;
  return 0;
}