//  Design a stack that supports getMin() in O(1) time and O(1) extra space

// link - https://www.naukri.com/code360/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465

/*
Problem statement
Create a stack data structure that allows operations such as push (adding an element), pop (removing the top element), top (retrieving the top element), and also provides a way to retrieve the minimum element in constant time.

Implement the following public functions :
1. push(data) : Pushes the element into the stack.
2. pop() : Removes the top element from the stack.
3. top() : Returns the element at the top of the stack.
4. getMin() : Returns the smallest element present in the stack.

Operations:
- 1 x: Push x onto the stack
- 2: Pop the top element
- 3: Print the top element
- 4: Print the minimum element
*/

#include <bits/stdc++.h>
using namespace std;

// OPTIMAL APPROACH:
// We use a single stack and a variable to keep track of the minimum.
// When pushing a new minimum, we encode the previous minimum in the stack.
// This allows getMin, push, pop, and top to all be O(1) and use O(1) extra space per element.
class SpecialStack
{
  stack<long long> st;
  long long mini;

public:
  SpecialStack() : mini(0) {}

  void push(int data)
  {
    if (st.empty())
    {
      st.push(data);
      mini = data;
    }
    else
    {
      if (data >= mini)
      {
        st.push(data);
      }
      else
      {
        // Encode previous min
        st.push(2LL * data - mini);
        mini = data;
      }
    }
  }

  void pop()
  {
    if (st.empty())
      return;
    long long t = st.top();
    st.pop();
    if (t < mini)
    {
      // Retrieve previous min
      mini = 2 * mini - t;
    }
  }

  int top()
  {
    if (st.empty())
      throw runtime_error("stack is empty");
    long long t = st.top();
    if (t >= mini)
      return t;
    else
      return mini;
  }

  int getMin()
  {
    if (st.empty())
      throw runtime_error("stack is empty");
    return mini;
  }

  bool empty() const { return st.empty(); }
};

// Helper to run a sequence of stack operations and collect outputs
vector<string> run_stack_operations(const vector<pair<int, int>> &queries)
{
  SpecialStack st;
  vector<string> output;
  for (const auto &q : queries)
  {
    int type = q.first;
    if (type == 1)
    {
      st.push(q.second);
    }
    else if (type == 2)
    {
      st.pop();
    }
    else if (type == 3)
    {
      output.push_back(to_string(st.top()));
    }
    else if (type == 4)
    {
      output.push_back(to_string(st.getMin()));
    }
  }
  return output;
}

void run_tests()
{
  vector<pair<int, int>> test1 = {
      {1, 13}, {1, 47}, {3, 0}, {1, 8}, {2, 0}, {4, 0}};
  vector<string> expected1 = {"47", "13"};
  auto out1 = run_stack_operations(test1);
  cout << "Test Case 1:\nInput: 1 13, 1 47, 3, 1 8, 2, 4\nExpected Output: 47 13\nYour Output:   ";
  for (auto &s : out1)
    cout << s << " ";
  cout << "\n"
       << (out1 == expected1 ? "PASS" : "FAIL") << "\n\n";

  vector<pair<int, int>> test2 = {
      {1, 45}, {2, 0}, {1, 53}, {4, 0}, {1, 46}, {4, 0}, {2, 0}, {4, 0}};
  vector<string> expected2 = {"53", "46", "53"};
  auto out2 = run_stack_operations(test2);
  cout << "Test Case 2:\nInput: 1 45, 2, 1 53, 4, 1 46, 4, 2, 4\nExpected Output: 53 46 53\nYour Output:   ";
  for (auto &s : out2)
    cout << s << " ";
  cout << "\n"
       << (out2 == expected2 ? "PASS" : "FAIL") << "\n\n";
}

int main()
{
  cout << "Running sample test cases...\n\n";
  run_tests();

  // Interactive mode for custom input
  cout << "Enter number of queries (Q) followed by Q queries (1 x, 2, 3, 4):\n";
  int Q;
  if (!(cin >> Q))
    return 0;
  vector<pair<int, int>> queries;
  for (int i = 0; i < Q; ++i)
  {
    int type, data = 0;
    cin >> type;
    if (type == 1)
      cin >> data;
    queries.emplace_back(type, data);
  }
  auto result = run_stack_operations(queries);
  for (auto &s : result)
    cout << s << endl;
  return 0;
}

/*
Time Complexity:
- push, pop, top, getMin: O(1) per operation

Space Complexity:
- O(N), where N is the number of elements in the stack
*/
