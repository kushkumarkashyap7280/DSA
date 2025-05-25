# Day 35: Prime Number Generation Algorithms

## Problems Explored

### Regular Sieve of Eratosthenes vs Segmented Sieve Implementation

In this study, we compared and implemented two important prime number generation algorithms:

#### 1. Simple Sieve of Eratosthenes

File: [regular_sieve_of_eratothenes_vs_segmented_sieve.cpp](./regular_sieve_of_eratothenes_vs_segmented_sieve.cpp)

##### Algorithm Steps:

1. Create a boolean array `isPrime[0..n]` initialized as true
2. Mark 0 and 1 as non-prime
3. For each number i from 2 to √n:
   - If isPrime[i] is true:
     - Mark all its multiples as false (starting from i\*i)
4. Collect remaining true values as prime numbers

##### Complexity Analysis:

- Time Complexity: O(n \* log(log(n)))
- Space Complexity: O(n)
- Suitable for: Small ranges (up to 10^7)

##### Limitations:

- High memory usage for large ranges
- Not efficient for finding primes in a range [L, R]

#### 2. Segmented Sieve

File: [regular_sieve_of_eratothenes_vs_segmented_sieve.cpp](./regular_sieve_of_eratothenes_vs_segmented_sieve.cpp)

##### Algorithm Steps:

1. Find all primes up to √R using simple sieve
2. Create a boolean array for segment [L, R]
3. For each prime p found in step 1:
   - Mark all multiples of p in range [L, R]
4. Remaining unmarked numbers in range are prime

##### Optimizations Implemented:

1. Special handling for number 2 (only even prime)
2. Skip even numbers > 2
3. Optimized multiple marking:
   - Start from p\*p or first multiple in range
   - Use 2\*p step size for marking
4. Type safety improvements:
   - Used long long for large numbers
   - Proper type casting for arithmetic operations

##### Complexity Analysis:

- Time Complexity: O(√R + (R-L+1) \* log(log(√R)))
- Space Complexity: O(√R + (R-L+1))
- Suitable for: Large ranges and memory-constrained environments

##### Key Advantages:

1. Memory Efficient:
   - Only requires O(√R) memory for base primes
   - Plus O(segment_size) for current segment
2. Cache Friendly:
   - Works on smaller segments at a time
   - Better cache utilization
3. Handles Large Ranges:
   - Can find primes in range [10^9, 10^9 + 10^6]
   - Efficient for sparse prime searches

## Implementation Details

### Key Features:

1. Edge Case Handling:

   ```cpp
   if (L <= 2) {
       if (L <= 2 && 2 <= R) cout << "2 ";
       L = std::max<long long>(3LL, L);
   }
   ```

2. Optimization for Even Numbers:

   ```cpp
   if (L % 2 == 0) L++;
   // Only check odd numbers
   for (long long i = 0; i < size; i += 2)
   ```

3. Efficient Multiple Marking:
   ```cpp
   long long start = std::max<long long>(static_cast<long long>(p) * p,
                                       ((L + p - 1) / p) * p);
   for (long long j = start; j <= R; j += 2 * p)
   ```

## Different Approaches to Check Prime Numbers

### 1. Trial Division Method

```cpp
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
```

- Time Complexity: O(√n)
- Space Complexity: O(1)
- Optimizations:
  - Check only up to square root
  - Skip even numbers and multiples of 3
  - Check only numbers of form 6k ± 1

### 2. Fermat's Primality Test

```cpp
bool fermatPrimalityTest(int n, int k) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    while (k--) {
        int a = 2 + rand() % (n - 4);
        if (__gcd(n, a) != 1) return false;

        // Fermat's little theorem
        if (modPow(a, n-1, n) != 1)
            return false;
    }
    return true;
}
```

- Probabilistic primality test
- Time Complexity: O(k \* log n)
- Can give false positives (Carmichael numbers)
- Good for large numbers

### 3. Miller-Rabin Primality Test

```cpp
bool millerRabin(int n, int k) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++) {
        if (!millerTest(n, d))
            return false;
    }
    return true;
}
```

- More accurate than Fermat's test
- Time Complexity: O(k \* log³n)
- Deterministic for n < 2⁶⁴
- No false positives for proper witnesses

### 4. Wilson's Theorem

```cpp
bool isWilsonPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;

    // Check if (n-1)! ≡ -1 (mod n)
    int factorial = n - 1;
    for (int i = n - 2; i > 1; i--) {
        factorial = (factorial * i) % n;
    }
    return factorial == n - 1;
}
```

- Based on (p-1)! ≡ -1 (mod p) for prime p
- Time Complexity: O(n)
- Impractical for large numbers
- Theoretically interesting

### 5. AKS Primality Test

- First deterministic primality test
- Polynomial time complexity: O(log¹²n)
- Historical importance in computational number theory
- Not practical for general use due to large constants

### Comparison of Methods

| Method                | Time Complexity         | Space | Accuracy        | Use Case         |
| --------------------- | ----------------------- | ----- | --------------- | ---------------- |
| Trial Division        | O(√n)                   | O(1)  | Perfect         | Small numbers    |
| Sieve of Eratosthenes | O(n log log n)          | O(n)  | Perfect         | Multiple queries |
| Segmented Sieve       | O(√n + (R-L)log log √n) | O(√n) | Perfect         | Range queries    |
| Fermat                | O(k log n)              | O(1)  | Probabilistic   | Large numbers    |
| Miller-Rabin          | O(k log³n)              | O(1)  | Deterministic\* | Cryptography     |
| Wilson's              | O(n)                    | O(1)  | Perfect         | Theoretical      |
| AKS                   | O(log¹²n)               | O(√n) | Perfect         | Theoretical      |

\* Deterministic for numbers up to 2⁶⁴ with proper witnesses

### Best Practices

1. For n < 10⁶: Use Trial Division or Sieve
2. For range queries: Use Segmented Sieve
3. For large numbers: Use Miller-Rabin
4. For cryptographic purposes: Use proven libraries

## Practice Problems

To further practice these concepts, try these problems:

1. [Count Primes - LeetCode 204](https://leetcode.com/problems/count-primes/)
2. [Prime Generator - SPOJ PRIME1](https://www.spoj.com/problems/PRIME1/)
3. [Almost Prime - Codeforces 26A](https://codeforces.com/problemset/problem/26/A)

## Common Pitfalls to Avoid

1. Integer overflow in calculations
2. Not handling edge cases (2, small ranges)
3. Inefficient memory usage
4. Not optimizing for even numbers
5. Incorrect segment size calculations

## Interview Tips

1. Always mention space optimization possibilities
2. Discuss the trade-offs between simple and segmented sieve
3. Consider the input range before choosing the algorithm
4. Be prepared to handle edge cases
5. Mention potential optimizations
