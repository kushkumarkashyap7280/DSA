// Selection Sort
// Selection sort is a simple and intuitive sorting algorithm. It works by repeatedly selecting the smallest (or largest) element from the unsorted portion of the array and swapping it with the first unsorted element. This process continues until the entire array is sorted.  
// The time complexity of selection sort is O(n^2) in the worst case, making it inefficient for large datasets. However, it has the advantage of being easy to understand and implement. Selection sort is not a stable sorting algorithm, meaning that it may change the relative order of equal elements in the sorted array.
// The space complexity of selection sort is O(1) since it only requires a constant amount of additional memory for the swap operation. This makes it an in-place sorting algorithm, which is a desirable property in many cases.

#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr, int n)
{   
  for(int i = 0 ; i < n-1;i++){
    int smallest = i+1;
    for(int j = i+1 ; j < n ; j++){
      if(arr[smallest]> arr[j]) smallest = j;
    }
    if(arr[i] >arr[smallest]){
      int temp = arr[smallest];
      arr[smallest] =arr[i];
      arr[i] = temp;
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
    selectionSort(arr, n);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
return 0;
}