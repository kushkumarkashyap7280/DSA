// to demonstrate how  to find maximum sum of row in 2D array


#include <iostream>
using namespace std;

// function to find maximum sum of row in 2D array
int find_max_sum_of_row(int *arr, int rows, int cols){
  int Max_row_sum = INT_MIN;
  for(int i = 0 ; i < rows ; i++){
    int temp_row_sum = 0;
    for(int j = 0; j < cols ; j++){
      temp_row_sum += *(arr + i* cols +j); // accessing 2D array using pointer arithmetic
    }
    if(temp_row_sum > Max_row_sum) Max_row_sum = temp_row_sum;
  }
  return Max_row_sum;
}

int main()
{
  // example 2D array
  int arr[3][3] = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};
    
  // dimensions of the array
        int rows = sizeof(arr) / sizeof(arr[0]);
  int cols = sizeof(arr[0]) / sizeof(arr[0][0]);

  int max_sum = find_max_sum_of_row(*arr, rows, cols);
  cout << "Maximum sum of row in the array is: " << max_sum << endl;


  
  return 0;
}