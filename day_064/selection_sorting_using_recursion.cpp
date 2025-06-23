//selection sort using recursion

#include <iostream>
// #include <utility>
using namespace std;

int minindex(int arr[], int i , int s , int mini ,int index){
  if(i >= s) return index;
  if(arr[i] < mini){
    mini = arr[i];
    index = i;
  }
  return minindex(arr , i+1 , s , mini ,index);
 
}
// main function of recursion 
void selection_sorting(int arr[] , int s , int i = 0){
  if(i >= s-1) return;
  int mini = minindex(arr , i, s , arr[i],i);
  if( i != mini){
     swap(arr[i] ,arr[mini]);
  }
  selection_sorting(arr , s , i+1);
}
int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);
  
  selection_sorting(arr, n);
  
  cout << "Sorted array: \n";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;


return 0;
}