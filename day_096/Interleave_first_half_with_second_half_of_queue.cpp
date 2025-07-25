#include <iostream>
#include <queue>
#include <vector>
// Interleave the First Half of the Queue with Second Half

// link -https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1

/*
Given a Queue of even size . Your task is to rearrange the queue by interleaving its first half with the second half.
Interleaving is the process of mixing two sequences by alternating their elements while preserving their relative order.
In other words, Interleaving means place the first element from the first half and then first element from the 2nd half and again 2nd element from the first half and then second element from the 2nd half and so on....

Examples:

Input: q = [2, 4, 3, 1]
Output: [2, 3, 4, 1]
Explanation: we place the first element of the first half 2 and after that place the first element of second half 3 and after that repeat
the same process one more time so the resulting queue will be [2, 3, 4, 1]
Input: q = [3, 5]
Output: [3, 5]
Explanation: We place the first element of the first half 3 and first element of the second half 5 so the resulting queue is [3, 5]


Constraints:
1 <=queue.size()<= 5*105
1 <=queue[i]<= 5*105
*/

std::queue<int> rearrangeQueue(std::queue<int> q)
{

  int s = q.size();
  std::vector<int> s1;
  std::vector<int> s2;
  for (int i = 0; i < s / 2; i++)
  {
    s1.push_back(q.front());
    q.pop();
  }

  while (!q.empty())
  {
    s2.push_back(q.front());
    q.pop();
  }

  for (int i = 0; i < s1.size(); i++)
  {
    q.push(s1[i]);
    if (i < s2.size())
      q.push(s2[i]);
  }
  return q;
}

// Demo main function for testing
int main()
{
  std::queue<int> q;
  q.push(2);
  q.push(4);
  q.push(3);
  q.push(1);
  std::queue<int> result = rearrangeQueue(q);
  std::cout << "Output: ";
  while (!result.empty())
  {
    std::cout << result.front() << " ";
    result.pop();
  }
  std::cout << std::endl; // Expected: 2 3 4 1

  std::queue<int> q2;
  q2.push(3);
  q2.push(5);
  std::queue<int> result2 = rearrangeQueue(q2);
  std::cout << "Output: ";
  while (!result2.empty())
  {
    std::cout << result2.front() << " ";
    result2.pop();
  }
  std::cout << std::endl; // Expected: 3 5
  return 0;
}