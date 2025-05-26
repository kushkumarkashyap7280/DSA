# Day 36: Modular Arithmetic

## Introduction to Modular Arithmetic

Modular arithmetic is a system of arithmetic for integers where numbers "wrap around" after reaching a certain value - the modulus.

### Basic Concepts

1. **Modulo Operation (%)**:

   ```cpp
   a % n = r  // where r is remainder when a is divided by n
   ```

   Example: 17 % 5 = 2 (17 = 3 × 5 + 2)

2. **Properties**:
   - (a + b) % m = ((a % m) + (b % m)) % m
   - (a - b) % m = ((a % m) - (b % m) + m) % m
   - (a × b) % m = ((a % m) × (b % m)) % m
   - (a^b) % m = ((a % m)^b) % m

## Common Applications

### 1. Fast Power (Binary Exponentiation)

```cpp
long long modPow(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
```

- Time Complexity: O(log n)
- Used in: Cryptography, Large number computations

### 2. Modular Multiplicative Inverse

```cpp
// Using Extended Euclidean Algorithm
int modInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1) return 0;

    while (a > 1) {
        int q = a / m;
        int t = m;

        m = a % m;
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    return x < 0 ? x + m0 : x;
}
```

- Exists only when a and m are coprime
- Used in: Division under modulo

### 3. Modular Division

```cpp
int modDivide(int a, int b, int m) {
    a = a % m;
    int inv = modInverse(b, m);
    return (inv * a) % m;
}
```

## Common Problems and Their Solutions

### 1. Large Factorial

Problem: Calculate n! % m

```cpp
int factorialMod(int n, int m) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result = (result * i) % m;
    }
    return result;
}
```

### 2. Large Fibonacci Numbers

Problem: Calculate nth Fibonacci number % m

```cpp
int fibonacciMod(int n, int m) {
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int c = (a + b) % m;
        a = b;
        b = c;
    }
    return b;
}
```

## Advanced Concepts

### 1. Chinese Remainder Theorem (CRT)

```cpp
// Returns minimum x such that:
// x % num[0] = rem[0]
// x % num[1] = rem[1]
// ...
long long crt(vector<int>& num, vector<int>& rem) {
    long long prod = 1;
    for (int i : num) prod *= i;

    long long result = 0;
    for (int i = 0; i < num.size(); i++) {
        long long pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }
    return result % prod;
}
```

### 2. Euler's Totient Function

```cpp
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
```

## Important Use Cases

1. **Cryptography**:

   - RSA algorithm
   - Digital signatures
   - Hash functions

2. **Programming Contests**:

   - Handling large numbers
   - Avoiding integer overflow
   - Computing large factorials

3. **Computer Science**:
   - Hash tables
   - Random number generation
   - Cyclic redundancy checks

## Common Pitfalls

1. **Negative Numbers**:

   - Use ((n % m) + m) % m for negative numbers

2. **Overflow in Intermediate Calculations**:

   - Use long long for intermediate results
   - Apply mod at each step

3. **Division Under Modulo**:
   - Need to use modular multiplicative inverse
   - Not all numbers have inverse (when not coprime with mod)

## Practice Problems

1. [LeetCode 372 - Super Pow](https://leetcode.com/problems/super-pow/)
2. [LeetCode 50 - Pow(x, n)](https://leetcode.com/problems/powx-n/)
3. [SPOJ - LASTDIG](https://www.spoj.com/problems/LASTDIG/)
4. [Codeforces - 1095C](https://codeforces.com/problemset/problem/1095/C)

## Interview Tips

1. Always handle edge cases:

   - Negative numbers
   - Zero
   - Large inputs

2. Optimize calculations:

   - Apply properties to reduce intermediate values
   - Use binary exponentiation for powers

3. Common moduli:

   - 10⁹+7 (Popular in competitive programming)
   - 998244353 (Another common prime modulus)

4. Remember basic properties:
   - (a + b) % m = ((a % m) + (b % m)) % m
   - Similar for multiplication

## Problem Deep Dive: LeetCode 50 - Pow(x, n)

### Problem Description

Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

#### Examples:

1. Input: x = 2.00000, n = 10
   Output: 1024.00000

2. Input: x = 2.10000, n = 3
   Output: 9.26100

3. Input: x = 2.00000, n = -2
   Output: 0.25000 (= 1/2²)

### Solution Approaches

#### 1. Brute Force Approach

```cpp
double myPow(double x, int n) {
    if (n == 0) return 1;
    if (n < 0) {
        x = 1/x;
        n = -n;
    }

    double result = 1;
    for (int i = 0; i < n; ++i) {
        result *= x;
    }
    return result;
}
```

##### Analysis:

- Time Complexity: O(n)
- Space Complexity: O(1)
- Approach:
  1. Handle base case (n = 0)
  2. Handle negative exponents by taking reciprocal
  3. Multiply x by itself n times
- Limitations:
  - Very slow for large values of n
  - Can cause TLE (Time Limit Exceeded)
  - Doesn't handle integer overflow cases well

#### 2. Optimized Approach (Binary Exponentiation)

```cpp
double myPow(double x, int n) {
    long long N = n;
    if(N == 0) return 1;
    if(n < 0) {
        x = 1/x;
        N = -N;
    }
    double ans = 1;
    while(N > 0) {
        if(N % 2 == 1) {
            ans *= x;
        }
        x *= x;
        N /= 2;
    }
    return ans;
}
```

##### Analysis:

- Time Complexity: O(log n)
- Space Complexity: O(1)
- Approach:
  1. Convert power to binary representation
  2. Use square-and-multiply algorithm
  3. For each bit in binary representation:
     - If bit is 1: multiply result by current x
     - Square x
     - Divide n by 2

##### Key Optimizations:

1. **Binary Representation Usage**:

   - Instead of n multiplications, use log(n) multiplications
   - Example: x⁸ = x⁴ × x⁴ instead of x × x × x × x × x × x × x × x

2. **Handling Edge Cases**:

   ```cpp
   long long N = n;  // Handle INT_MIN case
   ```

   - Using long long prevents overflow when n = INT_MIN
   - Important because |-INT_MIN| > INT_MAX

3. **Negative Exponents**:
   ```cpp
   if(n < 0) {
       x = 1/x;
       N = -N;
   }
   ```
   - Converts negative exponent to positive
   - Handles division at the start

### Example Walkthrough

For x = 2, n = 10:

1. 10 in binary = 1010
2. Process:
   - Start: ans = 1, x = 2
   - N = 10: x = 4, ans = 1
   - N = 5: x = 16, ans = 16
   - N = 2: x = 256, ans = 16
   - N = 1: x = 65536, ans = 1024
3. Final answer: 1024

### Common Pitfalls

1. Not handling negative exponents correctly
2. Integer overflow with INT_MIN
3. Precision errors with floating-point calculations
4. Not considering edge cases (0, 1, -1)

### Interview Tips

1. Always discuss the brute force approach first
2. Explain why binary exponentiation is better
3. Mention time/space complexity improvements
4. Discuss potential edge cases
5. Consider floating-point precision issues

This problem is a classic example of how mathematical insight (binary exponentiation) can dramatically improve algorithmic efficiency from O(n) to O(log n).

## Mathematical Principles in Competitive Programming

### 1. Pigeonhole Principle

The principle states that if n items are put into m containers, with n > m, then at least one container must contain more than one item.

#### Formal Definition:

- If n > m, then at least ⌈n/m⌉ items must be in the same container

#### Examples:

1. **Birthday Problem**:

```cpp
// At least two people have same birthday in a group of 367 people
bool hasSameBirthday(vector<int>& birthdays) {
    if (birthdays.size() > 365) return true;
    unordered_set<int> seen;
    for (int day : birthdays) {
        if (seen.count(day)) return true;
        seen.insert(day);
    }
    return false;
}
```

2. **Repeated Sequence**:

```cpp
// Find if a sequence has numbers that sum to multiple of n
bool hasSequenceSum(vector<int>& nums, int n) {
    vector<int> prefixSum(nums.size() + 1, 0);
    unordered_map<int, int> modCount;

    for(int i = 0; i < nums.size(); i++) {
        prefixSum[i+1] = (prefixSum[i] + nums[i]) % n;
        if(++modCount[prefixSum[i+1]] > 1) return true;
    }
    return false;
}
```

#### Applications:

1. Array Problems:
   - Finding duplicates
   - Finding cycles in sequences
2. Graph Theory:
   - Proving existence of certain paths
   - Coloring problems

#### Practice Problems:

1. [LeetCode 287 - Find the Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/)
2. [Codeforces - Divisible Array](https://codeforces.com/problemset/problem/1828/A)

### 2. Catalan Numbers

The nth Catalan number counts various combinatorial structures. Denoted as Cn, it follows the formula:
Cn = (1/(n+1)) \* (2n choose n)

#### Different Implementations:

1. **Using Binomial Coefficient** [GeeksForGeeks](https://www.geeksforgeeks.org/program-nth-catalan-number/):

```cpp
// Time Complexity: O(n)
// Space Complexity: O(1)
long long binomialCoeff(int n, int k) {
    long long res = 1;
    if (k > n - k) k = n - k; // Symmetry optimization

    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

long long findCatalan(int n) {
    return binomialCoeff(2 * n, n) / (n + 1);
}
```

**Advantages**:

- Most efficient for single number calculation
- No recursion overhead
- Minimal memory usage

2. **Using Factorial** [Implementation](./catalan_number_implementations.cpp):

```cpp
// Time Complexity: O(n) with larger constant
// Space Complexity: O(n) due to recursion
long long factorialof(int n) {
    if (n == 0 || n == 1) return 1;
    return (long long)n * factorialof(n - 1);
}

long long findCatalan(int n) {
    if (n == 0 || n == 1) return 1;
    return factorialof(2*n) / (factorialof(n+1) * factorialof(n));
}
```

**Limitations**:

- Recursive overhead
- Potential stack overflow for large n
- More multiplication operations

3. **Dynamic Programming** (For multiple queries):

```cpp
// Time Complexity: O(n²)
// Space Complexity: O(n)
vector<long long> generateCatalan(int n) {
    vector<long long> catalan(n + 1, 0);
    catalan[0] = catalan[1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i-1-j];
        }
    }
    return catalan;
}
```

**Best for**:

- Multiple Catalan numbers needed
- Avoiding overflow in intermediate calculations
- Better space efficiency than factorial approach

#### Practice Problems:

1. [Count the number of expressions - GeeksForGeeks](https://practice.geeksforgeeks.org/problems/count-the-number-of-expressions/1)
2. [Number of Unique BSTs - LeetCode 96](https://leetcode.com/problems/unique-binary-search-trees/)
3. [Valid Parentheses - LeetCode 22](https://leetcode.com/problems/generate-parentheses/)
4. [Mountain Ranges - GeeksForGeeks](https://practice.geeksforgeeks.org/problems/mountain-range/1)

#### Common Applications with Code Examples:

1. **Parentheses Combinations**:

```cpp
// Count valid parentheses combinations
long long validParentheses(int n) {
    return findCatalan(n);
}
```

2. **Unique BST Count**:

```cpp
// Count unique BST structures possible with n nodes
long long uniqueBSTCount(int n) {
    return findCatalan(n);
}
```

3. **Non-intersecting Chords**:

```cpp
// Count ways to connect 2n points on a circle with n non-intersecting chords
long long countNonIntersectingChords(int n) {
    return findCatalan(n);
}
```

#### Implementation Tips:

1. **Handling Overflow**:

   - Use `long long` for calculations
   - Consider modulo arithmetic for large numbers
   - Break down multiplications when possible

2. **Choosing Implementation**:

   - Single query → Binomial Coefficient approach
   - Multiple queries → DP approach
   - Small n → Any approach works
   - Large n → Consider modulo constraints

3. **Optimization Techniques**:
   - Use symmetry in binomial coefficient
   - Precompute for multiple queries
   - Use iterative over recursive when possible

### 3. Inclusion-Exclusion Principle

A counting technique to find the size of a union of multiple sets by considering their intersections.

#### Formula:

|A ∪ B ∪ C| = |A| + |B| + |C| - |A∩B| - |B∩C| - |A∩C| + |A∩B∩C|

#### Implementation:

```cpp
// Calculate numbers divisible by any of the given numbers
long long divisibleByNumbers(vector<int>& nums, long long n) {
    int size = nums.size();
    long long result = 0;

    // Iterate through all possible combinations
    for(int mask = 1; mask < (1 << size); mask++) {
        long long lcm = 1;
        int bits = __builtin_popcount(mask);

        // Calculate LCM of current combination
        for(int i = 0; i < size; i++) {
            if(mask & (1 << i)) {
                lcm = lcm_calculation(lcm, nums[i]);
                if(lcm > n) break;  // Optimization
            }
        }

        // Apply inclusion-exclusion
        if(bits & 1) {
            result += n / lcm;
        } else {
            result -= n / lcm;
        }
    }
    return result;
}

// Helper function to calculate LCM
long long lcm_calculation(long long a, long long b) {
    return (a / __gcd(a, b)) * b;
}
```

#### Applications:

1. **Counting Problems**:
   - Numbers divisible by given numbers
   - Elements satisfying multiple conditions
2. **Probability**:

   - Computing probability of union of events
   - Solving overlapping event problems

3. **Set Operations**:
   - Finding elements in at least k sets
   - Computing complement sets

#### Practice Problems:

1. [SPOJ - KQUERY](https://www.spoj.com/problems/KQUERY/)
2. [Codeforces - Almost All Multiples](https://codeforces.com/problemset/problem/1758/C)

### Common Interview Questions

1. **Pigeonhole Principle**:

   - Finding duplicate elements in array of n+1 integers from 1 to n
   - Proving existence of same sum subsequences

2. **Catalan Numbers**:

   - Count valid parentheses combinations
   - Number of unique BST structures
   - Non-crossing handshake problems

3. **Inclusion-Exclusion**:
   - Count numbers divisible by at least one of given numbers
   - Probability problems with overlapping events

### Tips for Using These Principles

1. **Pigeonhole Principle**:

   - Look for problems where items must be distributed
   - Useful in proving existence without constructing solution
   - Often combines with modular arithmetic

2. **Catalan Numbers**:

   - Recognize patterns: balanced parentheses, binary trees
   - Use DP for larger values
   - Remember the recurrence relation

3. **Inclusion-Exclusion**:
   - Draw Venn diagrams to visualize
   - Use bitmasks for efficient implementation
   - Consider complementary counting

Remember: These principles often provide elegant solutions to seemingly complex problems. Understanding when to apply them is key to solving many competitive programming problems efficiently.
