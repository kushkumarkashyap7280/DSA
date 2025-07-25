// 134. Gas Station
// Time Complexity: O(n) - Single pass through the gas and cost arrays.
// Space Complexity: O(1) - Uses only a constant amount of extra space.

// link - https://leetcode.com/problems/gas-station/description/

#include <iostream>
#include <vector>

/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.



Example 1:

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
Example 2:

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.


Constraints:

n == gas.length == cost.length
1 <= n <= 105
0 <= gas[i], cost[i] <= 104
The input is generated such that the answer is unique.
*/

class Solution
{
public:
  // brute force
  // int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
  //         int s  = gas.size();
  //     for(int i = 0 ; i < s; i++){
  //         int remaining_petrol = 0;
  //         bool isPossible = true;
  //         for(int j = i;  j < i+s;  j++ ){
  //             remaining_petrol  += gas[j%s] - cost[j%s];
  //              if(remaining_petrol < 0) {
  //                 isPossible = false;
  //                 break;
  //              }
  //         }
  //          if(isPossible) return i;
  //     }
  //     return -1;
  // }
  // my second approach
  int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost)
  {
    int s = gas.size();
    int total = 0; // i will decide whether we have enough petrol to complete the circle if >= 0 so yes other wise not
    int curr = 0;  // i am holding petrol from orgin index;
    int index = 0; // i am the index from where from journey starts
    for (int i = 0; i < s; i++)
    {
      total += gas[i] - cost[i]; //  lets add curr index we busy in calculating total over all till last simple
      curr += gas[i] - cost[i];  // lets add curr index  and later we will see

      if (curr < 0)
      { // i will tell that from where you should start if not possible from the  present index;

        index = i + 1; // now since curr dont have enough petol to reach next station .. it  implies that you should start from  ( i+1)th because every last contributed extra or  0 petrol so if after help from back petrol pumps it not possible so between none of them able to fullfill your needs;

        curr = 0; // since we starting again our origin change reset the curr petrol
      }
    }

    return total >= 0 ? index : -1; // if overall enough petrol in circle to complete it then yeah the curr index is the point we  can start so lets go , other wise not enough in the circle so not possible this journey return -1;
  }
};

// Demo main function for testing
int main()
{
  Solution sol;
  std::vector<int> gas1 = {1, 2, 3, 4, 5};
  std::vector<int> cost1 = {3, 4, 5, 1, 2};
  std::cout << "Test 1 Output: " << sol.canCompleteCircuit(gas1, cost1) << std::endl; // Expected: 3

  std::vector<int> gas2 = {2, 3, 4};
  std::vector<int> cost2 = {3, 4, 3};
  std::cout << "Test 2 Output: " << sol.canCompleteCircuit(gas2, cost2) << std::endl; // Expected: -1
  return 0;
}