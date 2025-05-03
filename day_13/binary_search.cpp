// binary search algorithm: This project implements a binary search algorithm to find the position of a target value in a sorted array.
// The binary search algorithm is efficient and has a time complexity of O(log n).
// The algorithm works by repeatedly dividing the search interval in half until the target value is found or the interval is empty.
// The binary search algorithm is implemented in the `binary_search` function, which takes a sorted array and a target value as input and returns the index of the target value in the array or -1 if the target value is not found.  

#include <iostream>

using namespace std;

int binarysearch (int arr[] , int size ,int wanttosearch){
  int start = 0;
  int end = size -1;

  while(start <= end){
    int mid = (start + end)/2;
    if(arr[mid]== wanttosearch) return mid;
    if(wanttosearch > arr[mid]){
      start = mid + 1;
    }else{
      end = mid - 1;
    };
    mid = (start + end)/2;

  };
  return -1;

};

int main (){
  int arr[10]= { 1,2,3,4,5,6,7,8,9,10};
  cout << "Enter the number you want to search: ";
  int wanttosearch;
  cin >> wanttosearch;

  int size = sizeof(arr)/sizeof(arr[0]);
  int index = binarysearch(arr,size,wanttosearch);
  if(index == -1){
    cout << "The number is not in the array" << endl;
  }else{
    cout << "The number is in the array at index: " << index << endl;
  };
  

};