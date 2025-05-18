// This project is built using the C++14 standard.
// find the pivot index in a rotated sorted array
// The pivot index is the index of the smallest element in the rotated sorted array.
// The array is rotated at some pivot unknown to you beforehand.

#include <iostream>
using namespace std;


// fisrt approach
// This approach uses a binary search to find the pivot index in a rotated sorted array.
// The pivot index is the index of the smallest element in the rotated sorted array.

int pivot(int arr[], int n) {
    int i = 0, j = n - 1;
    while (i <= j) {
        int mid = i + (j - i) / 2;
        
        // If mid is the pivot
        if (arr[mid] < arr[j] && (mid == 0 || arr[mid] < arr[mid - 1])) {
            return mid;
        }

        // If left part is sorted, pivot must be in the right part
        if (arr[mid] >= arr[i]) {
            i = mid + 1;
        }
        // Otherwise, pivot must be in the left part
        else {
            j = mid - 1;
        }
    }
    return -1; // No pivot found
}


// second approach
// This approach uses a binary search to find the pivot index in a rotated sorted array.
// The pivot index is the index of the smallest element in the rotated sorted array.
int findPivot(int arr[], int n) {
    int i = 0, j = n - 1;

    while (i < j) {
        int mid = i + (j - i) / 2;
        
        if (arr[mid] > arr[j]) {
            // Pivot must be in the right part
            i = mid + 1;
        } else {
            // Pivot is in the left part, including mid
            j = mid;
        }
    }
    return i;  // or j, since i == j
}


int main() {
    
    int arr[] = { 15 , 16 ,17 , 18 , 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int pivotIndex = pivot(arr, n);
    if (pivotIndex != -1) {
        cout << "Pivot index: " << pivotIndex << endl;
    } else {
        cout << "No pivot found." << endl;
    }
    // Output: Pivot index: 4
return 0;
}