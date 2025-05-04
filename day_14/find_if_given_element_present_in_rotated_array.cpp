#include <iostream>
using namespace std;
int  pivot ( int arr[] , int n){

  int i = 0 , j = n-1;
  while(i<j){
    int mid = i + (j- i)/2;
    
    if(arr[mid] > arr[j]){
       i = mid + 1;

    }else{
      j = mid;
    }
  }
  return i;
};

bool ispresent(int arr[] , int n , int target){
  int k = pivot(arr, n);
  int i , j ;
  if(arr[k] == target) { return true;}
  else if (arr[k] <= target && arr[n-1] >= target){
    i = k ;
    j = n-1;
  }else{
    i = 0;
    j = k -1;
  };

  while(i<=j){
    int mid = i + (j- i)/2;
     if(arr[mid]== target) { return true;}
     else if( arr[mid] < target) {
      i = mid + 1;
     }
     else{
       j = mid -1;
     }
  }

  return false;

};

int main() {
  int arr[] = {6, 7, 8, 1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 9;
    if (ispresent(arr, n, target)) {
        cout << "Target " << target << " is present in the array.\n";
    } else {
        cout << "Target " << target << " is NOT present in the array.\n";
    }
  
return 0;
}