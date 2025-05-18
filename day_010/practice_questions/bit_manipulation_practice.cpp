#include <iostream>
using namespace std;

// Question 1: Check if number is even or odd using bitwise operator
bool isEven(int n)
{
  return !(n & 1); // If last bit is 0, number is even
}

// Question 2: Find number which appears once while others appear twice
int findSingle(int arr[], int n)
{
  int result = 0;
  for (int i = 0; i < n; i++)
  {
    result ^= arr[i]; // XOR all numbers
  }
  return result;
}

// Question 3: Count number of set bits (1s) in a number
int countSetBits(int n)
{
  int count = 0;
  while (n)
  {
    count += n & 1; // Check last bit
    n >>= 1;        // Right shift by 1
  }
  return count;
}

// Question 4: Check if a number is power of 2
bool isPowerOfTwo(int n)
{
  return n && !(n & (n - 1)); // n & (n-1) will be 0 for powers of 2
}

// Question 5: Find position of rightmost set bit
int getRightmostSetBit(int n)
{
  int position = 1;
  int m = 1;

  while (!(n & m))
  {
    m = m << 1;
    position++;
  }
  return position;
}

int main()
{
  // Test even/odd
  cout << "Is 4 even? " << isEven(4) << endl;
  cout << "Is 7 even? " << isEven(7) << endl;

  // Test single number
  int arr[] = {2, 3, 2, 4, 3, 4, 5};
  cout << "Single number: " << findSingle(arr, 7) << endl;

  // Test counting set bits
  cout << "Set bits in 7: " << countSetBits(7) << endl;

  // Test power of 2
  cout << "Is 8 power of 2? " << isPowerOfTwo(8) << endl;
  cout << "Is 10 power of 2? " << isPowerOfTwo(10) << endl;

  // Test rightmost set bit
  cout << "Position of rightmost set bit in 12: " << getRightmostSetBit(12) << endl;

  return 0;
}
