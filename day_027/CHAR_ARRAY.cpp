// CHAR ARRRAY
// C++ program to demonstrate the working of char arrays
#include <iostream>
using namespace std;

// function to get length of char array;
int length(char arr[]){
  int count = 0;
  for(int i = 0 ; arr[i] != '\0' ; i++){
    count++;
  }
  return count;
}
// function which reverse the char array;
void Reverse(char arr[]){
  int start = 0;
  int end = length(arr) - 1;
  while(start < end){
    char temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;
    start++;
    end--;
  }
}

int main()
{
    // declaring and initializing char array
    char name[20];
    cout << "Enter your name: ";



    cin >> name; // not safe

    // name[2] = '\0'; // null character

    // cin.getline(name, 20); // safe
    // cin.get(name, 20); // safe

    cout << "Your name is: " << name << endl;
    cout << "Length of name is: " << length(name) << endl;
    cout << "Size of name is: " << sizeof(name) << endl;
    cout << "Size of name is: " << sizeof(name)/sizeof(name[0]) << endl;
    Reverse(name);
    cout << "reversed name is: " << name << endl;

    return 0;
}