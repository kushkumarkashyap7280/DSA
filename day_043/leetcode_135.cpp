// 135. Candy

// https://leetcode.com/problems/candy/

/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.



Example 1:

Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.


Constraints:

n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// Function to calculate the minimum number of candies needed
//time complexity: O(n)
//space complexity: O(n)
int candy(vector<int> &ratings)
{
  int s = ratings.size();
  vector<int> candy_distribution(s, 1);

  // Left to right pass
  for (int i = 1; i < s; i++)
  {
    if (ratings[i] > ratings[i - 1])
    {
      candy_distribution[i] = candy_distribution[i - 1] + 1;
    }
  }

  // Right to left pass
  for (int i = s - 2; i >= 0; i--)
  {
    if (ratings[i] > ratings[i + 1])
    {
      candy_distribution[i] = max(candy_distribution[i], candy_distribution[i + 1] + 1);
    }
  }

  // Sum up all candies
  return accumulate(candy_distribution.begin(), candy_distribution.end(), 0);
}
int main()
{
  vector<int> ratings = {1, 0, 2};
  cout << "Minimum number of candies needed: " << candy(ratings) << endl; // Output: 5
  ratings = {1, 2, 2};
  cout << "Minimum number of candies needed: " << candy(ratings) << endl; // Output: 4
  ratings = {1, 3, 2, 2, 1};
  cout << "Minimum number of candies needed: " << candy(ratings) << endl; // Output: 7
  return 0;
}