// Insertion sorting
#include <iostream>
#include <vector>
using namespace std;

void InsertionSort(vector<int>& arr, int n)
{   
   for(int i = 1; i < n; i++) {
        int key = arr[i];     // current element to be inserted
        int j = i - 1;

        // Shift larger elements one position to the right
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the current element into its correct position
        arr[j + 1] = key;
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
    InsertionSort(arr, n);
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
return 0;
}