// bubble sorting algorithm
// Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The pass through the
// list is repeated until the list is sorted. The algorithm gets its name from the way smaller elements "bubble" to the top of the list.
//
// The time complexity of bubble sort is O(n^2) in the worst case, making it inefficient for large datasets. However, it has the advantage of being easy to understand and implement. Bubble sort is not a stable sorting algorithm, meaning that it may change the relative order of equal elements in the sorted array.
// The space complexity of bubble sort is O(1) since it only requires a constant amount of additional memory for the swap operation. This makes it an in-place sorting algorithm, which is a desirable property in many cases.


#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int>& arr, int n)
{   
  for(int i = 0 ; i < n-1;i++){
    int j = 0;
    while(j < n-1-i){
      if(arr[j] > arr[j+1]){
         int temp = arr[j+1];
         arr[j+1]=arr[j];
         arr[j]=temp;

      }
      j++;
    }
  }
}

int main() {
    
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    bubbleSort(arr, n);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
return 0;
}