// Padding and Alignment in Classes Example
#include <iostream>
#include <cstddef> // for offsetof
using namespace std;

class Inefficient
{
public:
  char a; // 1 byte
  int b;  // 4 bytes
  char c; // 1 byte
          // Padding will be added by compiler for alignment
};

class Efficient
{
public:
  int b;  // 4 bytes
  char a; // 1 byte
  char c; // 1 byte
          // Less padding needed
};

int main()
{
  cout << "Size of Inefficient class: " << sizeof(Inefficient) << " bytes\n";
  cout << "Offsets: a=" << offsetof(Inefficient, a) << ", b=" << offsetof(Inefficient, b) << ", c=" << offsetof(Inefficient, c) << endl;
  cout << "Size of Efficient class:   " << sizeof(Efficient) << " bytes\n";
  cout << "Offsets: b=" << offsetof(Efficient, b) << ", a=" << offsetof(Efficient, a) << ", c=" << offsetof(Efficient, c) << endl;

  cout << "\nWhy minimize padding?" << endl;
  cout << "- Padding is extra unused memory added for alignment.\n";
  cout << "- Less padding = less memory usage, better cache performance.\n";
  cout << "\nHow to optimize?" << endl;
  cout << "- Group larger data members first, then smaller ones.\n";
  cout << "- Avoid unnecessary gaps between members.\n";
  return 0;
}
