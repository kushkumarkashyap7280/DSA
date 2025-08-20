// ============================= HEAP =====================

// what is heap ?

// heap is a data structure that is used to store data in a tree-like structure.

// heap is a complete binary tree what that mean ?

// means heap a all complete nodes at each level except lowest one

// heap should follow heap properities

// 1. max heap properity

// here parent should always have greater value than childs

// 2. min heap properity

// here parent should  alwyas have  lesser value than both childs





// things to remember 

// given array 

// [x , 1 , 2 , 3 , 4 , 5 , 6 , 7]

// here x is root

//  things we noticed that 

// ith parent is  (ith /2) index

// ith left child is (2 * i ) index

// ith right child is (2* i  + 1) index





#include <iostream>
#include <algorithm>
using namespace std;

struct heap{
    int arr[101];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    // insertion
    void insert(int val){
        if(size >= 100){
            cout << "full alredy" << endl;
            return;
        }

       int index = ++size;
       arr[index] = val;
       while(index > 1 && arr[index/2] < arr[index]){
              swap(arr[index/2], arr[index]);
              index /= 2;
       }
    }


    // deletion

    void deletion(){
        if(size == 0){
            cout << "already empty" << endl;
            return;
        }
        int index = 1;
        arr[index] = arr[size--];
      
while (index * 2 <= size) {
        int left = index * 2;
        int right = index * 2 + 1;
        int largest = index;

        if (left <= size && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right <= size && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != index) {
            swap(arr[index], arr[largest]);
            index = largest;
        } else {
            break;
        }
    }
}


    void print(){
        
        for(int i = 1 ; i <=  size ; i++){
            cout << arr[i] << " -> " ;
        }
        cout << endl;
    }
};
int main() {

    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    h.deletion();

    h.print();
    
return 0;
}


