// reverse a string using stack

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Time Complexity: O(n), where n is the length of the input string.
// Space Complexity: O(n), due to the stack storing all characters.
// function to reverse a string using stack
string reverseStr(string s)
{
  stack<char> st;
  for (char c : s)
    st.push(c);
  string ans = "";
  while (st.top())
  {
    ans.push_back(st.top());
    st.pop();
  }
  return ans;
}
int main()
{
  string input;
  cout << "Enter a string to reverse: ";
  getline(cin, input);
  string reversed = reverseStr(input);
  cout << "Reversed string: " << reversed << endl;
  return 0;
}