//121. Best Time to Buy and Sell Stock

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum profit from stock prices
//time complexity: O(n)
//space complexity: O(1)
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX; // Initialize minimum price to maximum possible value
    int maxProfit = 0; // Initialize maximum profit to 0

    for (int price : prices) {
        if (price < minPrice) {
            minPrice = price; // Update minimum price if current price is lower
        } else if (price - minPrice > maxProfit) {
            maxProfit = price - minPrice; // Update maximum profit if current profit is higher
        }
    }

    return maxProfit; // Return the maximum profit found
}
int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4}; // Example stock prices
    int result = maxProfit(prices); // Call the function to calculate maximum profit
    cout << "Maximum Profit: " << result << endl; // Output the result
return 0;
}