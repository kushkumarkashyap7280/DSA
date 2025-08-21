// ============= heapify algorithm ================

/*
🔍 What is Heapify?
Heapify is a process used to maintain the heap property:

In a max heap, every parent node must be greater than or equal to its children.
In a min heap, every parent node must be less than or equal to its children.
There are two types:

Heapify-up (used during insertion): You compare the inserted node with its parent and swap if necessary.
Heapify-down (used during deletion): You compare the root with its children and swap with the larger (or smaller, for min heap) child if needed.

*/

///  in heapify algo we make  complete binary tree using when given uneven numbers and using heapfiy we  fix that and make heap

//[x ,1 ,2 ,3 ,4 ,5 ,6]
// we dont need  to make  (n/2 + 1 ) index to n make heap they are leaf nodes so alreyd a heap since there is no child they have

// #include <iostream>
// #include <algorithm>
// using namespace std;

// class heap
// {

// public:
//   int size;
//   int arr[101];

//   heap()
//   {
//     arr[0] = -1;
//     size = 0;
//   }

//   // insertion

//   void insertion(int val)
//   {
//     if (size >= 100)
//     {
//       cout << "already filled " << endl;
//       return;
//     }

//     size++;
//     int index = size;
//     arr[index] = val;
//     while (index > 1 && arr[index / 2] < arr[index])
//     {
//       swap(arr[index / 2], arr[index]);
//       index /= 2;
//     }
//   }

//   // deletion
//   void deletion()
//   {
//     if (size <= 0)
//     {
//       cout << "nothing to delete here " << endl;
//     }

//     swap(arr[1], arr[size]);
//     int index = 1;

//     while (index <= size)
//     {
//       int l = index * 2;
//       int r = (index * 2) + 1;
//       int largest = index;
//       if (l < size && arr[l] > arr[index])
//       {
//         largest = l;
//       }
//       if (r < size && arr[r] > arr[index])
//       {
//         largest = r;
//       }

//       if (largest != index)
//       {
//         swap(arr[index], arr[largest]);
//         index = largest;
//       }
//       else
//       {
//         return;
//       }
//     }
//   }

// };

//   void heapify(int arr[], int n, int i)
//   {
//     int largest = i;
//     int l = 2 * i;
//     int r = 2 * r;
//     if (l < n && arr[l] > arr[largest])
//     {
//       largest = l;
//     }
//     if (r < n && arr[r] > arr[largest])
//     {
//       largest = r;
//     }

//     if (largest != i)
//     {
//       swap(arr[i], arr[largest]);
//       largest = largest;
//       heapify(arr , n , i);
//     }
//   }

// int main()
// {
//    int n = 5;
//   int arr[6] = {-1 , 54, 53, 55 ,52, 50};

//   for(int i = n/2 ; i > 0; i--){
//      heapify(arr , n, i);
//   }

//   // print array now
//   for(int i = 1 ; i < n; i++){
//     cout << arr[i] << " -> " ;
//   }
//   cout << endl;
//   return 0;
// }

// link - https://www.naukri.com/code360/problems/build-min-heap_1171167

#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
  int largest = i;
  int l = 2 * i;
  int r = 2 * i + 1;
  if (l <= n && arr[l] > arr[largest])
    largest = l;
  if (r <= n && arr[r] > arr[largest])
    largest = r;
  if (largest != i)
  {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
  }
}

// ---------------------
// Test Infrastructure
// ---------------------
static void expectEq(const vector<int> &got, const vector<int> &want, const string &testName)
{
  if (got != want)
  {
    cerr << "[FAIL] " << testName << ": expected [";
    for (size_t i = 0; i < want.size(); ++i)
      cerr << want[i] << (i + 1 < want.size() ? ", " : "");
    cerr << "], got [";
    for (size_t i = 0; i < got.size(); ++i)
      cerr << got[i] << (i + 1 < got.size() ? ", " : "");
    cerr << "]\n";
    exit(1);
  }
  else
  {
    cout << "[PASS] " << testName << "\n";
  }
}

static void runTests()
{
  // Test 1: Example from code
  {
    int n = 5;
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    for (int i = n / 2; i > 0; i--)
      heapify(arr, n, i);
    vector<int> got(arr + 1, arr + n + 1);
    vector<int> want{55, 53, 54, 52, 50};
    expectEq(got, want, "Example 1");
  }
  // Test 2: Already a max heap
  {
    int n = 5;
    int arr[6] = {-1, 100, 90, 80, 70, 60};
    for (int i = n / 2; i > 0; i--)
      heapify(arr, n, i);
    vector<int> got(arr + 1, arr + n + 1);
    vector<int> want{100, 90, 80, 70, 60};
    expectEq(got, want, "Already max heap");
  }
  // Test 3: All equal
  {
    int n = 4;
    int arr[5] = {-1, 5, 5, 5, 5};
    for (int i = n / 2; i > 0; i--)
      heapify(arr, n, i);
    vector<int> got(arr + 1, arr + n + 1);
    vector<int> want{5, 5, 5, 5};
    expectEq(got, want, "All equal");
  }
  // Test 4: Single element
  {
    int n = 1;
    int arr[2] = {-1, 42};
    for (int i = n / 2; i > 0; i--)
      heapify(arr, n, i);
    vector<int> got(arr + 1, arr + n + 1);
    vector<int> want{42};
    expectEq(got, want, "Single element");
  }
  // Test 5: Empty
  {
    int n = 0;
    int arr[1] = {-1};
    for (int i = n / 2; i > 0; i--)
      heapify(arr, n, i);
    vector<int> got(arr + 1, arr + n + 1);
    vector<int> want{};
    expectEq(got, want, "Empty");
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  runTests();
  return 0;
}