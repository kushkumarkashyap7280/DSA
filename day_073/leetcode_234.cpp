// 234. Palindrome Linked List

// https://leetcode.com/problems/palindrome-linked-list/

/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.



Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false


Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9


Follow up: Could you do it in O(n) time and O(1) space?
*/

#include <iostream>
#include <vector>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// brute force approach
// 1. Traverse the linked list and store the values in a vector.
// 2. Use two pointers to compare the values from the start and end of the vector.
// 3. If all values match, return true; otherwise, return false.
// time complexity: O(n)
// space complexity: O(n)
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head)
            return true;
        if (!head->next)
            return true;
        ListNode *curr = head;
        vector<int> r;
        while (curr != nullptr)
        {
            r.push_back(curr->val);
            curr = curr->next;
        }
        int i = 0, j = r.size() - 1;
        while (i < j)
        {
            if (r[i] != r[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

// using pointers approach
// time complexity O(n)
// space complexity O(1)
bool isPalindrome(ListNode *head)
{
    if (!head)
        return false;
    ListNode *fast = head;
    ListNode *slow = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast)
        slow = slow->next;

    ListNode *prev = nullptr;
    ListNode *curr = slow;
    while (curr)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    fast = head;
    while (prev)
    {
        if (prev->val != fast->val)
            return false;
        prev = prev->next;
        fast = fast->next;
    }
    return true;
}
int main()
{
    // Example usage
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));

    Solution solution;
    bool result = solution.isPalindrome(head);

    cout << (result ? "true" : "false") << endl; // Output: true

    // Clean up memory
    while (head != nullptr)
    {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}