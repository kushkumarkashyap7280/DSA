// here we define a simple recursive function to calculate the factorial of a number
// what is recursion: Recursion is a programming technique where a function calls itself to solve a problem.
// In this example, we will implement a recursive function to calculate the factorial of a number.
//recusion used to solve problems that can be broken down into smaller subproblems of the same type.
// we hava base case and a recursive case in our function.

#include <iostream>
using namespace std;
// Function to calculate factorial using recursion
int factorial(int n){
  cout << "Calculating factorial of " << n << endl; // Debug statement
  // Base case: if n is 0 or 1, return 1
  if(n == 0 || n == 1) {
    return 1; // Base case: factorial of 0 or 1 is 1
  } else {
    return n * factorial(n - 1); // Recursive case
  }
}
int main() {
  int number;
  cout << "Enter a number to calculate its factorial: ";
  cin >> number; // Input from user
  if (number < 0) {
    cout << "Factorial is not defined for negative numbers." << endl;
  } else {
    int result = factorial(number); // Call the recursive function
    cout << "Factorial of " << number << " is " << result << endl; // Output the result
  }
return 0;
}