// peak of mountain array
// Given an array of integers that is initially increasing and then decreasing, find the peak element in the array.
// The peak element is the element that is greater than its neighbors. If the array is empty, return -1. If the array has only one element, return that element. If the array has two elements, return the maximum of the two elements.



// class Solution {
//   public:
//       int peakIndexInMountainArray(vector<int>& arr) {
//             int i = 1 , j = arr.size()-2;
//           while(i <= j){
//               int middle = i + (j-i)/2;
//               if(arr[middle] >= arr[middle -1] && arr[middle] >= arr[middle + 1]  ){
//                  return middle;
//               };
//               if(arr[middle] >= arr[middle -1] && arr[middle] <= arr[middle]  ){
//                   i = middle + 1;
//               };
//                 if(arr[middle] <= arr[middle -1] && arr[middle] >= arr[middle]  ){
//                   j = middle -1;
//               };
//           }
//           return -1;
//       }
//   };