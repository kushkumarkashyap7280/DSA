# Day 52: LeetCode 121 - Best Time to Buy and Sell Stock

## Problem Analysis

### Problem Statement

Given an array of stock prices where `prices[i]` represents the price on day i, find the maximum profit you can achieve by:

- Buying one stock on a day
- Selling it on a different day in the future
  Return 0 if no profit is possible.

### Constraints

- 1 ≤ prices.length ≤ 10⁵
- 0 ≤ prices[i] ≤ 10⁴
- Must buy before selling

## Solution Approach

### Algorithm: Single Pass with Min Price Tracking

The solution uses a single pass through the array while maintaining:

1. Minimum price seen so far
2. Maximum profit possible with current price

### Implementation Details

```cpp
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;  // Track minimum price
    int maxProfit = 0;       // Track maximum profit

    for (int price : prices) {
        // Update minimum price if current price is lower
        if (price < minPrice) {
            minPrice = price;
        }
        // Update maximum profit if selling at current price gives better profit
        else if (price - minPrice > maxProfit) {
            maxProfit = price - minPrice;
        }
    }

    return maxProfit;
}
```

### Key Points

1. **Minimum Price Tracking**:

   - Keep track of lowest price seen
   - Initialize to INT_MAX for first comparison
   - Update when lower price found

2. **Profit Calculation**:

   - Calculate potential profit at each step
   - Only update if new profit is higher
   - No need to track selling day explicitly

3. **Single Pass**:
   - Only need to traverse array once
   - No need for nested loops
   - Linear time complexity

## Complexity Analysis

### Time Complexity: O(n)

- Single pass through the array
- Each element processed once
- Constant time operations per element

### Space Complexity: O(1)

- Only two variables used
- Space independent of input size
- No additional data structures

## Test Cases

### Example 1

```
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation:
- Buy on day 2 (price = 1)
- Sell on day 5 (price = 6)
- Profit = 6 - 1 = 5
```

### Example 2

```
Input: prices = [7,6,4,3,1]
Output: 0
Explanation:
- Prices only decrease
- No profit possible
```

## Edge Cases

1. **Decreasing Array**:

   - All prices decreasing
   - Should return 0

2. **Single Element**:

   - Array with one price
   - Should return 0

3. **Same Prices**:

   - All prices same
   - Should return 0

4. **Large Numbers**:
   - Prices near maximum value
   - Handle without overflow

## Code Structure

1. **Variable Initialization**:
   - minPrice for tracking minimum
   - maxProfit for tracking profit
2. **Single Loop**:

   - Process each price once
   - Update minimums and maximums

3. **Result Return**:
   - Return maximum profit found
   - Zero if no profit possible

## Common Pitfalls

1. **Buying/Selling Order**:

   - Must buy before selling
   - Can't use future prices for buying

2. **Profit Calculation**:

   - Calculate from minimum price
   - Update only if better profit found

3. **Edge Cases**:
   - Handle decreasing prices
   - Handle single-day cases

## Real-world Applications

1. **Financial Analysis**:

   - Stock market trading
   - Asset price analysis
   - Investment strategies

2. **Optimization Problems**:
   - Resource allocation
   - Timing decisions
   - Price optimization

## Implementation Tips

1. Initialize minimum price to INT_MAX
2. Track both minimum price and maximum profit
3. Update minimum before calculating profit
4. Consider edge cases carefully
5. Use single pass for efficiency

## Related Problems

1. Best Time to Buy and Sell Stock II (LeetCode 122)
2. Best Time to Buy and Sell Stock III (LeetCode 123)
3. Best Time to Buy and Sell Stock with Cooldown (LeetCode 309)
