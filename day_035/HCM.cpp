// here we are make a algorithm to find the HCM of two numbers

#include <iostream>
using namespace std;

// Function to find the highest common factor (HCM) of two numbers
// using a simple iterative approach
// time complexity: O(n)
// space complexity: O(1)
int Factor_of(int m , int n){
  if(m > n) return Factor_of(n, m);
  int HCM = 1;
  for(int i = 2; i <= m; i++){
    if(m%i== 0 && n%i == 0) HCM =i;
  }
  return HCM;
}

// Euclid's algorithm for finding the highest common factor (HCM)
// of two numbers using recursion

// concept: The Euclidean algorithm is based on the principle that the HCM of two numbers also divides their difference.
// It repeatedly replaces the larger number by the remainder of the division of the two numbers until one of them becomes zero.


// time complexity: O(log(min(m, n)))
// space complexity: O(1)
int Euclid(int m, int n) {
  if (m < n) return Euclid(n, m); // Ensure m is always greater than or equal to n
  if (n == 0) return m; // Base case: if n is 0, return m as the HCM
  return Euclid(n, m % n); // Recursive case: call Euclid with n and the remainder of m divided by n
}
int main() {
  int m, n;
  cout << "Enter two numbers: ";
  cin >> m >> n;
  
  if(m <= 0 || n <= 0) {
    cout << "Please enter positive integers only." << endl;
    return 1;
  }

  // int hcm = Factor_of(m, n);
  int hcm = Euclid(m, n);
  
  if(hcm == 1) {
    cout << "The numbers are co-prime." << endl;
  } else {
    cout << "The highest common factor (HCM) of " << m << " and " << n << " is: " << hcm << endl;
  }
return 0;
}