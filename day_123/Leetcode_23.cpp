#include <queue>
#include <vector>
using namespace std;

// Definition for singly-linked list node
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 23. Merge k Sorted Lists
// Link: https://leetcode.com/problems/merge-k-sorted-lists/

/*
Problem Description:
Given an array of k sorted linked lists, merge them into a single sorted linked list.

Approaches:
1. Min Heap (Priority Queue) - O(N*log k):
   - Store head nodes of all lists in min heap
   - Always extract minimum node
   - Push next node from same list to heap

2. Divide and Conquer - O(N*log k):
   - Similar to merge sort
   - Recursively merge pairs of lists
   - Reduces number of comparisons

Key Insights:
1. Min Heap Solution:
   - Need custom comparator for ListNode*
   - Only k nodes in heap at a time
   - Maintains sorted order naturally

2. Divide and Conquer:
   - Reduces from k-way to 2-way merge
   - Better cache locality
   - Recursive vs iterative implementation

Example Walkthrough:
Input: [[1,4,5],[1,3,4],[2,6]]

Min Heap Steps:
1. Initial heap: [1,1,2]
2. Pop 1, push 4: [1,2,4]
3. Pop 1, push 3: [2,3,4]
4. Pop 2, push 6: [3,4,6]
... continue until all nodes processed

Time Complexity: O(N * log k) where:
- N = total nodes across all lists
- k = number of lists
- log k for heap operations

Space Complexity:
- O(k) for heap storage
- O(1) additional space (reusing input nodes)

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.



Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []


Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
*/

// Solution class implementing both approaches:
class Solution
{
  // Helper function to merge two sorted lists
  // Used in divide and conquer approach
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    // Dummy node to simplify list building
    ListNode dummy(0);
    ListNode *tail = &dummy;

    // Compare and link nodes in sorted order
    while (l1 && l2)
    {
      if (l1->val < l2->val)
      {
        tail->next = l1;
        l1 = l1->next;
      }
      else
      {
        tail->next = l2;
        l2 = l2->next;
      }
      tail = tail->next;
    }

    // Attach remaining nodes, if any
    if (l1)
      tail->next = l1;
    if (l2)
      tail->next = l2;

    return dummy.next;
  }

  // Alternate solution using divide and conquer approach
  ListNode *mergeKListsDivideConquer(vector<ListNode *> &lists)
  {
    int n = lists.size();
    if (n == 0)
      return nullptr;

    // Keep merging pairs until only one list remains
    while (n > 1)
    {
      int k = (n + 1) / 2; // Ceiling division
      // Merge pairs of lists
      for (int i = 0; i < n / 2; i++)
      {
        lists[i] = mergeTwoLists(lists[i], lists[i + k]);
      }
      n = k; // Update number of lists
    }
    return lists[0];
  }

  // Custom comparator for min heap
  // Makes heap order nodes by their values (smallest on top)
  struct compare
  {
    bool operator()(ListNode *a, ListNode *b)
    {
      return a->val > b->val; // Min heap, so reverse comparison
    }
  };

public:
  // Main function to merge k sorted lists using min heap approach
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {

    // Create min heap to store head nodes of all lists
    priority_queue<ListNode *, vector<ListNode *>, compare> pq;

    // Initialize heap with first node of each list
    // Skip empty lists
    for (int i = 0; i < lists.size(); i++)
    {
      if (lists[i])
        pq.push(lists[i]);
    }

    // Dummy node to simplify list building
    ListNode dummy(0);
    ListNode *curr = &dummy; // Current pointer for building result
    // Process nodes until heap is empty
    while (!pq.empty())
    {
      // Get & remove smallest value node
      ListNode *top = pq.top();
      pq.pop();

      // Add to result list
      curr->next = top;
      curr = curr->next;

      // If this node has next, add it to heap
      if (top->next)
        pq.push(top->next);
    }

    // Return merged list (skip dummy node)
    return dummy.next;
  }
};