// insertion sorting using recursion

#include <iostream>
#include <algorithm>
using namespace std;

// inner function to find the correct position for the key
// and shift elements accordingly
int  inner_function(int arr[],int j, int key){
   if(j >= 0 && arr[j] > key){
   arr[j+1] = arr[j];

    return inner_function(arr , j-1 , key);
   }else{
    return j;
   }
}
// main recursive function to perform insertion sort
// it takes the array, size of the array, and current index as parameters


void insertion_sorting(int arr[],int s ,int i = 1){
  if( i >=s) return;
  int key = arr[i];
  int j = i -1;

    j = inner_function(arr , j, key );
    arr[j+1] =key;
   return insertion_sorting(arr , s , i+1);
}
int main() {

  int arr[] = {12, 11, 13, 5, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  
  insertion_sorting(arr, n);
  
  cout << "Sorted array: \n";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
 
return 0;
}