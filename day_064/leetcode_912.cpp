// Merge sorting using recursion


#include <iostream>
#include <vector>
using namespace std;

 void inserting(vector<int>&arr,vector<int> &half ,int l ,int r ,int i =0){
        if(l >r) return;
        half[i] = arr[l];
        return inserting(arr , half , l+1 , r ,i +1);
        
    }
    void  merge(vector<int>&arr , int l , int m , int r){
        vector<int> left(m-l +1 , 0);
        vector<int>  right(r -m, 0);
        
        inserting(arr , left , l , m);
          inserting(arr , right, m+1 , r);
          
         int i = 0 , j =0 , k = l;
         while( i < left.size() && j < right.size()){
             if(left[i] <= right[j]){
                 arr[k++] = left[i++];
             }else{
                 arr[k++] = right[j++];
             }
         }
         while( i< left.size()) arr[k++] = left[i++];
          while( j< right.size()) arr[k++] = right[j++];
         
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if (l >= r) return;

        int m = l +( r -l)/2;
        
        mergeSort(arr , l , m);
        mergeSort(arr , m +1 , r);
        
        merge(arr ,l ,m ,r);
    }
// For testing
int main() {

    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // Output should be the sorted array
    // 3 9 10 27 38 43 82
    return 0;
}