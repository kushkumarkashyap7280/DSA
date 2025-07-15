// 84. Largest Rectangle in Histogram
// Problem Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Approach 1: Brute Force (Expand Left and Right for Each Bar)
- For each bar, expand to the left and right as long as the bars are at least as tall as the current bar.
- Time Complexity: O(n^2)
- Space Complexity: O(1)

Approach 2: Precompute Nearest Smaller to Left and Right (Monotonic Stack)
- For each bar, precompute the index of the first smaller bar to the left and right using stacks.
- Then, for each bar, the width is (right[i] - left[i] - 1).
- Time Complexity: O(n)
- Space Complexity: O(n)

Approach 3: Single Pass Stack (Optimal)
- Use a stack to keep indices of increasing bar heights. When a lower bar is found, calculate area for all higher bars.
- Time Complexity: O(n)
- Space Complexity: O(n)
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// first approach :
// int minRight(vector<int>& heights ,int index){
//   int unit = 0;
//   int i = index+1 ;
//   while(i < heights.size() && heights[i] >= heights[index]){
//       unit++;
//       i++;
//   }
//   return unit;
// }
// int minLeft(vector<int>& heights ,int index){
//     int unit = 0;
//   int i = index-1 ;
//   while(i >= 0 && heights[i] >= heights[index]){
//       unit++;
//       i--;
//   }
//   return unit;
// }
// int largestRectangleArea(vector<int>& heights) {
//  int maxArea = 0;
//  for(int i = 0 ; i < heights.size(); i++){
//     int b = maxRight(heights , i) + maxLeft(heights , i) +1;
//     int area = b * heights[i];
//     if(area > maxArea) maxArea = area;
//  }
// return maxArea;
// }

// optimal 2nd approach :

// void minRight(vector<int> &heights, vector<int> &right)
// {
//   int n = heights.size();
//   stack<int> index;
//   for (int i = n - 1; i >= 0; i--)
//   {
//     if (!index.empty() && heights[index.top()] >= heights[i])
//     {
//       while (!index.empty() && heights[index.top()] >= heights[i])
//         index.pop();
//     }
//     if (!index.empty())
//     {
//       right[i] = index.top();
//     }
//     else
//     {
//       right[i] = n;
//     }
//     index.push(i);
//   }
// }
// void minLeft(vector<int> &heights, vector<int> &left)
// {
//   int n = heights.size();
//   stack<int> index;
//   for (int i = 0; i < n; i++)
//   {
//     if (!index.empty() && heights[index.top()] >= heights[i])
//     {
//       while (!index.empty() && heights[index.top()] >= heights[i])
//         index.pop();
//     }
//     if (!index.empty())
//     {
//       left[i] = index.top();
//     }
//     else
//     {
//       left[i] = -1;
//     }
//     index.push(i);
//   }
// }
// int largestRectangleArea(vector<int> &heights)
// {

//   int n = heights.size();

//   vector<int> right(n, 0);
//   vector<int> left(n, 0);

//   minRight(heights, right);
//   minLeft(heights, left);
//   int maxArea = 0;
//   for (int i = 0; i < n; i++)
//   {
//     int w = right[i] - left[i] - 1;
//     int area = heights[i] * w;
//     maxArea = max(area, maxArea);
//   }
//   return maxArea;
// }

// third optimal in space complexity too approach :

int largestRectangleArea(vector<int> &heights)
{
  heights.push_back(0); // sentinel
  stack<int> st;
  int maxArea = 0;

  for (int i = 0; i < heights.size(); ++i)
  {
    while (!st.empty() && heights[i] < heights[st.top()])
    {
      int h = heights[st.top()];
      st.pop();
      int w = st.empty() ? i : i - st.top() - 1;
      maxArea = max(maxArea, h * w);
    }
    st.push(i);
  }

  return maxArea;
}

// Sample main function to demonstrate usage
int main()
{
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  cout << "Input: [2, 1, 5, 6, 2, 3]" << endl;

  // Uncomment to test Approach 1 (Brute Force)
  // cout << "Approach 1 (Brute Force) Output: " << largestRectangleArea(heights) << endl;

  // Uncomment to test Approach 2 (Precompute Nearest Smaller to Left and Right)
  // cout << "Approach 2 (Monotonic Stack) Output: " << largestRectangleArea(heights) << endl;

  // Approach 3 (Single Pass Stack, Optimal)
  cout << "Approach 3 (Single Pass Stack) Output: " << largestRectangleArea(heights) << endl;

  return 0;
}
