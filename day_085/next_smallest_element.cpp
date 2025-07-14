#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
  vector<int> ans(n);
  stack<int> temp;
  temp.push(-1);
  for (int i = n - 1; i >= 0; i--)
  {
    while (temp.top() != -1 && arr[i] <= temp.top())
      temp.pop();
    ans[i] = temp.top();
    temp.push(arr[i]);
  }
  return ans;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
      cin >> arr[i];
    vector<int> res = nextSmallerElement(arr, n);
    for (int i = 0; i < n; ++i)
      cout << res[i] << (i == n - 1 ? '\n' : ' ');
  }
  return 0;
}