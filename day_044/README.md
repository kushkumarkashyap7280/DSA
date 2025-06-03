# Day 44 - Large Number Multiplication Algorithms

## LeetCode 43: Multiply Strings

[Problem Link](https://leetcode.com/problems/multiply-strings/)

Given two non-negative integers as strings, return their product as a string, without using BigInteger or direct integer conversion.

## Solution Approaches

### 1. Traditional Multiplication (Grade School Algorithm)

This approach mimics how we multiply numbers by hand.

#### Algorithm Explanation

1. **Initialize Result**: Start with a result array/string to store partial products
2. **Digit-by-Digit Multiplication**:
   - For each digit in second number from right to left:
     - Multiply it with first number
     - Add appropriate number of zeros based on position
     - Add to result
3. **Handle Carry**: Maintain carry in each step of multiplication and addition

```cpp
string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    string ans = "0";

    // For each digit in num2
    for(int i = num2.size() - 1; i >= 0; i--) {
        // Multiply num1 with current digit and add zeros
        string product = mul(num1, num2[i], num2.size() - 1 - i);
        // Add to final result
        ans = Sum(ans, product);
    }
    return ans;
}
```

#### Time & Space Complexity

- **Time Complexity**: O(n \* m) where n, m are lengths of input strings
- **Space Complexity**: O(n + m) for storing result

#### Example Walkthrough

```
num1 = "123"
num2 = "456"

Step 1: 123 × 6
        738    (add 0 zeros)
Step 2: 123 × 50
       6150    (add 1 zero)
Step 3: 123 × 400
      49200    (add 2 zeros)
Result: 56088  (sum all partial products)
```

### 2. Karatsuba Algorithm

A faster multiplication algorithm using divide-and-conquer strategy.

#### Algorithm Explanation

1. **Base Cases**:

   - If either number is 0, return 0
   - If numbers are small, use traditional multiplication

2. **Divide**: Split each number into two parts

   - For number with n digits:
     - First half: first n/2 digits
     - Second half: remaining digits

3. **Recursive Steps**:
   For numbers split as (a × 10^n/2 + b) and (c × 10^n/2 + d):

   - Calculate ac = a × c
   - Calculate bd = b × d
   - Calculate (a+b)(c+d) = ac + ad + bc + bd
   - Calculate ad + bc = (a+b)(c+d) - ac - bd

4. **Combine**:
   Result = ac × 10^n + (ad + bc) × 10^n/2 + bd

```cpp
string multiplyKaratsuba(string num1, string num2) {
    // Base cases
    if (num1 == "0" || num2 == "0") return "0";
    if (num1.size() < 2 || num2.size() < 2)
        return multiply(num1, num2);

    // Split numbers
    int n = max(num1.size(), num2.size());
    int half = n / 2;

    // Divide into parts
    string a = num1.substr(0, num1.size() - half);
    string b = num1.substr(num1.size() - half);
    string c = num2.substr(0, num2.size() - half);
    string d = num2.substr(num2.size() - half);

    // Recursive calculations
    string ac = multiplyKaratsuba(a, c);
    string bd = multiplyKaratsuba(b, d);
    string abcd = multiplyKaratsuba(Sum(a, b), Sum(c, d));

    // Combine results
    string adbc = Sum(Sum(ac, bd), bd);

    // Add zeros for position value
    for (int i = 0; i < 2 * half; i++) ac.push_back('0');
    for (int i = 0; i < half; i++) adbc.push_back('0');

    return Sum(Sum(ac, adbc), bd);
}
```

#### Time & Space Complexity

- **Time Complexity**: O(n^log₂(3)) ≈ O(n^1.585)
- **Space Complexity**: O(n log n) due to recursive calls

#### Example Using Karatsuba

```
Multiply 123 × 456

1. Split numbers:
   123 = 1 × 10² + 23
   456 = 4 × 10² + 56

2. Calculate:
   ac = 1 × 4 = 4
   bd = 23 × 56
   (a+b)(c+d) = 24 × 60

3. Combine with appropriate zeros
   Final result: 56088
```

### Key Differences Between Approaches

1. **Performance**:

   - Traditional: Simpler but slower for very large numbers
   - Karatsuba: Faster for large numbers but more complex implementation

2. **Memory Usage**:

   - Traditional: Uses less memory
   - Karatsuba: Uses more memory due to recursion

3. **Implementation Complexity**:
   - Traditional: Easier to understand and implement
   - Karatsuba: More complex, requires careful handling of string operations

### When to Use Which Approach

1. **Use Traditional Multiplication When**:

   - Numbers are relatively small (< 1000 digits)
   - Memory is constrained
   - Code simplicity is priority

2. **Use Karatsuba Algorithm When**:
   - Dealing with very large numbers
   - Performance is critical
   - Memory usage is not a constraint

## Problem 2: LeetCode 2652 - Sum Multiples

[Problem Link](https://leetcode.com/problems/sum-multiples/)

Find the sum of all integers in range [1, n] that are divisible by 3, 5, or 7.

### Solution Approaches

#### 1. Brute Force Approach

Iterate through all numbers and check divisibility.

```cpp
int sumOfMultiples(int n) {
    int sum = 0;
    for (int i = 3; i < n + 1; i++) {
        if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
            sum += i;
        }
    }
    return sum;
}
```

**Complexity Analysis**:

- Time Complexity: O(n) - iterate through each number
- Space Complexity: O(1) - only use a sum variable

#### 2. Optimal Mathematical Approach

Uses arithmetic progression formula for efficient calculation.

```cpp
int sumOfMultiplesOptimal(int n) {
    return (n / 3) * (n / 3 + 1) / 2 * 3 +
           (n / 5) * (n / 5 + 1) / 2 * 5 +
           (n / 7) * (n / 7 + 1) / 2 * 7;
}
```

**Mathematical Explanation**:

1. For a number k, sum of multiples up to n = k _ (⌊n/k⌋ _ (⌊n/k⌋ + 1) / 2)
2. Formula breakdown for k = 3:
   - ⌊n/3⌋ = number of multiples of 3
   - ⌊n/3⌋ \* (⌊n/3⌋ + 1) / 2 = sum of sequence from 1 to ⌊n/3⌋
   - Multiply by 3 to get actual sum of multiples

**Complexity Analysis**:

- Time Complexity: O(1) - constant operations
- Space Complexity: O(1) - no extra space needed

### Example Walkthrough

```
Input: n = 10

Brute Force:
- Check each number from 3 to 10
- Divisible numbers: 3, 5, 6, 7, 9, 10
- Sum = 40

Optimal Approach:
1. For multiples of 3:
   - ⌊10/3⌋ = 3 terms (3, 6, 9)
   - 3 * (3 * 4) / 2 = 18

2. For multiples of 5:
   - ⌊10/5⌋ = 2 terms (5, 10)
   - 5 * (2 * 3) / 2 = 15

3. For multiples of 7:
   - ⌊10/7⌋ = 1 term (7)
   - 7 * (1 * 2) / 2 = 7

Total = 18 + 15 + 7 = 40
```

### Key Insights

1. **Mathematical Properties**:

   - Understanding arithmetic sequences
   - Using floor division properties
   - Avoiding double counting (needs consideration for numbers divisible by multiple values)

2. **Optimization Benefits**:

   - Constant time vs linear time
   - No iteration needed
   - Scales well for large inputs

3. **Trade-offs**:
   - Brute force: Simple but slower
   - Optimal: Faster but requires mathematical understanding
   - Memory usage same for both approaches
