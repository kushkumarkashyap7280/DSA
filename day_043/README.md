# Day 43 - Problem Solving Techniques

## Problem 1: LeetCode 135 - Candy Distribution

### Greedy Algorithm Approach

### Problem Description

[Problem Link](https://leetcode.com/problems/candy/)

Given `n` children standing in a line with ratings, distribute candies following these rules:

- Each child must get at least 1 candy
- Children with higher ratings get more candies than their neighbors

### Solution Approach: Two-Pass Algorithm

The solution uses a greedy approach with two passes through the array:

1. **Left to Right Pass**: Ensure children with higher ratings than their left neighbor get more candies
2. **Right to Left Pass**: Ensure children with higher ratings than their right neighbor get more candies

```cpp
int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);  // Initialize with 1 candy each

    // Left to right pass
    for(int i = 1; i < n; i++) {
        if(ratings[i] > ratings[i-1]) {
            candies[i] = candies[i-1] + 1;
        }
    }

    // Right to left pass
    for(int i = n-2; i >= 0; i--) {
        if(ratings[i] > ratings[i+1]) {
            candies[i] = max(candies[i], candies[i+1] + 1);
        }
    }
}
```

### Complexity Analysis

- **Time Complexity**: O(n) - Two linear passes through the array
- **Space Complexity**: O(n) - Additional array to store candy distribution

### Example

```
Input: ratings = [1,0,2]
Output: 5
Explanation:
- Child 1 gets 2 candies (more than Child 2)
- Child 2 gets 1 candy
- Child 3 gets 2 candies (more than Child 2)
Total = 2 + 1 + 2 = 5
```

### Key Insights

1. **Greedy Choice**: Always give minimum required candies at each step
2. **Two-Pass Necessity**: Single pass can't handle all cases as we need to look at both neighbors
3. **Local Optimization**: Focus on satisfying local conditions leads to global optimal solution

### Why Two Passes?

- **First Pass**: Handles increasing sequences from left
- **Second Pass**: Adjusts for increasing sequences from right
- **Taking Maximum**: Ensures both conditions are met simultaneously

### Common Pitfalls

1. Forgetting to initialize with 1 candy each
2. Not using max() in the second pass
3. Only doing one pass (insufficient)

## Problem 2: LeetCode 415 - Add Strings

### String Manipulation & Basic Math

### Problem Description

[Problem Link](https://leetcode.com/problems/add-strings/)

Given two non-negative integers represented as strings, return their sum as a string without using built-in big integer libraries or converting inputs to integers directly.

### Solution Approach: Digit-by-Digit Addition

```cpp
string addStrings(string num1, string num2) {
    string ans;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += num1[i--] - '0';
        if (j >= 0) sum += num2[j--] - '0';
        ans.push_back('0' + (sum % 10));
        carry = sum / 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
```

### Complexity Analysis

- **Time Complexity**: O(max(n,m)) where n, m are lengths of input strings
- **Space Complexity**: O(max(n,m)) for the result string

### Key Insights

1. **Character to Integer**: Using `char - '0'` to convert digit characters to integers
2. **Carry Handling**: Managing carry in base-10 addition
3. **Reverse Processing**: Building result in reverse order for efficiency
4. **No Built-in Conversion**: Solving without converting strings to integers

### Example

```
Input: num1 = "11", num2 = "123"
Output: "134"
Explanation:
- Process from right to left
- 1 + 3 = 4
- 1 + 2 = 3
- 0 + 1 = 1
Result: "134"
```

### Implementation Notes

1. Process digits from right to left (least significant to most significant)
2. Handle different length inputs gracefully
3. Account for final carry if present
4. Build result in reverse order and flip at the end
