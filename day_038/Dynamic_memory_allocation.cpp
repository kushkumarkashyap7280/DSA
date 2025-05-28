// here we dynamically allocate memory for an array of integers
// what is dynamic memory allocation?
// Dynamic memory allocation is a method of allocating memory at runtime, allowing for flexible memory usage.

#include<iostream>
using namespace std;

int getSum(int *arr, int n) {

    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    } 
    return sum;
}

int main() {

    int n;
    cin >> n;
    
    //variable size array
    int* arr = new int[n];

    //takign inputn in aray
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = getSum(arr, n);

    cout << "answer is "<< ans << endl;

//case 1
    while(true) {
        int i = 5;
    }
    
//case 2
    while(true) {
        int* ptr = new int;
    }




    return 0;
}