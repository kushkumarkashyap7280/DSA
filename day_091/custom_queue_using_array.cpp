// using  array lets built our own queue



#include <iostream>
using namespace std;

class array_queue{
  int curr_Index; // curr index of tail 
  int  n; // fix size of arr
  int* arr; // arr

  public:

  array_queue(int n) :
  n(n) ,curr_Index(-1) ,arr(new int[n]){}

  ~array_queue(){
    delete[] arr;
  }
  
  void push(int a){
    if(curr_Index >= n-1){
      cout << " no space left in queue " << endl;
      return;
    }
    arr[++curr_Index] = a;

  }
  void pop(){
    if(curr_Index == -1){
      cout << "nothing to remove " << endl;
      return;
    }
    int i = 0;
    while(i < curr_Index){
        swap(arr[i] ,arr[i+1]);
        i++;
    }
    curr_Index--;
  }

  int front(){
    if( curr_Index == -1)  throw runtime_error(" queue is empty");
    return arr[0];
  }

  int size(){
     return curr_Index+1;
  }

  bool isempty(){
     if(curr_Index > -1) return false;
     return true;
  }

  void iterate(){
    int i = 0;
    cout << "front = " ;
     while( i <= curr_Index){
      cout << arr[i]  << "->";
      i++;
     }
  }

};

int main(){

  array_queue k(5);
  
  cout << "is queue is empty :" << k.isempty() << endl;
  k.push(0);
  k.push(1);
  k.push(2);
  k.push(3);
  k.push(4);

  cout << "is queue is empty :" << k.isempty() << endl;
  cout << "front is :" << k.front() << endl;
  cout << "size is :"<< k.size() << endl;

  k.iterate();

  k.pop();

  cout << "front is :" << k.front() << endl;
  cout << "size is :"<< k.size() << endl;

  k.iterate();
  cout << "is queue is empty :" << k.isempty() << endl;

  return 0;
}

