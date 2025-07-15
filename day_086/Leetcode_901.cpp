
#include <iostream>
#include <stack>
#include <vector>
#include <utility>
using namespace std;

// 901. Online Stock Span
// link - https://leetcode.com/problems/online-stock-span/description/
/*
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
*/


// my sol : 
// class StockSpanner {

//   vector<int> arr;
//   stack<int> lastGreaterPrice;
// public:
//   StockSpanner() {
//       arr.push_back(INT_MAX);
//       lastGreaterPrice.push(0);
//   }
  
//   int next(int price) {
//       arr.push_back(price);
//     while(arr[lastGreaterPrice.top()] <= price ){
//       lastGreaterPrice.pop();
//     }
//     int span = arr.size()-1 - lastGreaterPrice.top();
//     lastGreaterPrice.push(arr.size()-1);
//   return span;
//   }
// }; 

class StockSpanner
{
  stack<pair<int, int>> priceIndex;
  int day = 0;

public:
  StockSpanner() {}

  int next(int price)
  {
    ++day; // increment day counter
    // pop all prices ≤ current price
    while (!priceIndex.empty() && priceIndex.top().first <= price)
    {
      priceIndex.pop();
    }
    int span;
    if (priceIndex.empty())
    {
      span = day;
    }
    else
    {
      span = day - priceIndex.top().second;
    }
    priceIndex.push({price, day});
    return span;
  }
};

// Time Complexity: O(1) amortized per next() call (each price is pushed and popped at most once)
// Space Complexity: O(N), where N is the number of calls to next()

int main()
{
  StockSpanner stockSpanner;
  int prices[] = {100, 80, 60, 70, 60, 75, 85};
  int n = sizeof(prices) / sizeof(prices[0]);
  cout << "StockSpanner Test Cases:\n";
  for (int i = 0; i < n; ++i)
  {
    cout << "next(" << prices[i] << ") = " << stockSpanner.next(prices[i]) << endl;
  }
  // Expected output: 1, 1, 1, 2, 1, 4, 6
  return 0;
}