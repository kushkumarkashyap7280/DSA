//11. Container With Most Water

//https://leetcode.com/problems/container-with-most-water/

/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

 

Example 1:


Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
 

Constraints:

n == height.length
2 <= n <= 105
0 <= height[i] <= 104
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// function to find the maximum area of water that can be contained
// time complexity: O(n)
// space complexity: O(1)
 int maxArea(vector<int>& height) {
       long long Max_area = 0;
       int i = 0;
       int j = height.size()-1;
       while(i < j){
        int w = j - i;
        int h = min(height[i],height[j]);
         long long temp_area = 1LL * h * w;
         if(temp_area >= Max_area){
           Max_area = max(Max_area, temp_area);
           
         }
          if(height[i] <= height[j]){
                i++;
            }else{
                j--;
            }
       }
       return Max_area;
    }
int main() {
  //example
  vector<int> height = {1,8,6,2,5,4,8,3,7};
  cout << "Maximum area of water that can be contained: " << maxArea(height) << endl;
  // Output: 49
return 0;
}