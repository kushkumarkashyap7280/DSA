// First and Last Position of an Element In Sorted Array
// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.
// Example:
// Input: 'arr' = [0,1,1,5] , 'k' = 1

// Output: 1 2

// Explanation:
// If 'arr' = [0, 1, 1, 5] and 'k' = 1, then the first and last occurrence of 1 will be 1(0 - indexed) and 2.

// #include <bits/stdc++.h> 
// int firstoccurance(vector<int>& arr, int n,int k){
//     int i = 0 , j = arr.size() -1;
//     int firstOccurance = -1;
//     while(i <= j){
//         int  middle = i + (j - i)/2 ;
//         if(arr[middle]== k){ firstOccurance = middle ; j = middle -1;  }
//         else if(arr[middle]< k){  i = middle +1;  }
//         else{
//            j = middle -1;
//         }

//     }
//     return firstOccurance;


// };
// int lastoccurance(vector<int>& arr, int n,int k){
//     int i = 0 , j = arr.size() -1;
//     int lastOccurance = -1;
//     while(i <= j){
//         int  middle = i + (j - i)/2 ;
//         if(arr[middle]== k){ lastOccurance = middle ; i = middle +1; }
//        else if(arr[middle]< k){  i = middle +1;  }
//         else{
//            j = middle -1;
//         }


//     }
//     return lastOccurance;


// };
// pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
// { 
//     return{firstoccurance(arr , n ,k), lastoccurance(arr, n ,k)};
//  }