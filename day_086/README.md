## Leetcode 3136: Valid Word

**Problem Link:** [Leetcode 3136 - Valid Word](https://leetcode.com/problems/valid-word/description)
**Solution File:** [Leetcode_3136.cpp](./Leetcode_3136.cpp)

**Problem:**
A word is valid if:

- It has at least 3 characters
- Contains only digits and English letters
- Has at least one vowel (a, e, i, o, u, case-insensitive)
- Has at least one consonant (English letter that is not a vowel)

**Approach:**

- Check length
- Iterate through each character:
  - If not a digit or letter, return false
  - Track if at least one vowel and one consonant are present
- Return true if both are present

**Time Complexity:** O(N), where N is the length of the word (max 20)
**Space Complexity:** O(1)

**Code Snippet:**

```cpp
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Solution {
  public:
      bool isValid(string word) {
          string v = "aeiou";
          if(word.size()< 3) return false;
          bool HasVowel = false;
          bool HasConsonant = false;
          for(char c : word){
              char s = tolower(c);
              if( s >= 'a' && s <= 'z'){
                  if(v.find(s) != string::npos){
                      HasVowel = true;
                  }else{
                      HasConsonant = true;
                  }
              }else if(s >= '0' && s <='9'){
                  continue;
              }else{
                  return false;
              }
          }
          return HasVowel && HasConsonant;
      }
};
```

## Leetcode 901: Online Stock Span

**Problem Link:** [Leetcode 901 - Online Stock Span](https://leetcode.com/problems/online-stock-span/description/)
**Solution File:** [Leetcode_901.cpp](./Leetcode_901.cpp)

**Problem:**
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day. The span is the maximum number of consecutive days (starting from today and going backward) for which the stock price was less than or equal to today's price.

**Approach:**

- Use a stack to keep track of prices and their indices (days).
- For each new price, pop from the stack until the top is greater than the current price.
- The span is the difference between the current day and the day of the last higher price (or the current day if none).

**Time Complexity:** O(1) amortized per next() call (each price is pushed and popped at most once)
**Space Complexity:** O(N), where N is the number of calls to next()

**Code Snippet:**

```cpp
#include <iostream>
#include <stack>
#include <utility>
using namespace std;

class StockSpanner {
    stack<pair<int, int>> priceIndex;
    int day = 0;
public:
    StockSpanner() {}
    int next(int price) {
        ++day;
        while (!priceIndex.empty() && priceIndex.top().first <= price) {
            priceIndex.pop();
        }
        int span = priceIndex.empty() ? day : day - priceIndex.top().second;
        priceIndex.push({price, day});
        return span;
    }
};
```

## second approch my solution

**Code Snippet:**

```cpp
class StockSpanner {

    vector<int> arr;
    stack<int> lastGreaterPrice;
public:
    StockSpanner() {
        arr.push_back(INT_MAX);
        lastGreaterPrice.push(0);
    }

    int next(int price) {
        arr.push_back(price);
      while(arr[lastGreaterPrice.top()] <= price ){
        lastGreaterPrice.pop();
      }
      int span = arr.size()-1 - lastGreaterPrice.top();
      lastGreaterPrice.push(arr.size()-1);
    return span;
    }
};


```

## Leetcode 84: Largest Rectangle in Histogram

**Problem Link:** [Leetcode 84 - Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)
**Solution File:** [Leetcode_84.cpp](./Leetcode_84.cpp)

**Problem:**
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

**Approaches:**

- **Approach 1: Brute Force (Expand Left and Right for Each Bar)**

  - For each bar, expand to the left and right as long as the bars are at least as tall as the current bar.
  - **Time Complexity:** O(n^2)
  - **Space Complexity:** O(1)

- **Approach 2: Precompute Nearest Smaller to Left and Right (Monotonic Stack)**

  - For each bar, precompute the index of the first smaller bar to the left and right using stacks.
  - Then, for each bar, the width is (right[i] - left[i] - 1).
  - **Time Complexity:** O(n)
  - **Space Complexity:** O(n)

- **Approach 3: Single Pass Stack (Optimal)**
  - Use a stack to keep indices of increasing bar heights. When a lower bar is found, calculate area for all higher bars.
  - **Time Complexity:** O(n)
  - **Space Complexity:** O(n)
