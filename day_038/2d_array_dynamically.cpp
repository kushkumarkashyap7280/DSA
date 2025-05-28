// here we demonstrate how to create a 2D array dynamically in C++ using pointers
#include <iostream>
using namespace std;
int main() {
int rows, cols;
cout << "Enter number of rows: ";
cin >> rows;
cout << endl;
cout << "Enter number of columns: ";
cin >> cols;
cout << endl;
// Dynamically allocate a 2D array
int** arr = new int*[rows]; // Allocate memory for each row
for (int i = 0; i < rows; i++) {
    arr[i] = new int[cols]; // Allocate memory for each column in the row
}
// Input values into the 2D array
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        cout << "Enter value for arr[" << i << "][" << j << "]: ";
        cin >> arr[i][j];
    }
}
// Output the 2D array
cout << "The 2D array is:" << endl;
for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
        cout << arr[i][j] << " ";
    }
    cout << endl;
}
// Deallocate memory for the 2D array
for (int i = 0; i < rows; i++) {
    delete[] arr[i]; // Delete each row
}
delete[] arr; // Delete the array of pointers
cout << "Memory deallocated successfully." << endl;
return 0;
}