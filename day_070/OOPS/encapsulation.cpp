// Encapsulation Example
#include <iostream>
using namespace std;

class Account
{
private:
  double balance;

public:
  void deposit(double amt) { balance += amt; }
  double getBalance() { return balance; }
  Account() : balance(0) {}
};

int main()
{
  Account acc;
  acc.deposit(1000);
  cout << acc.getBalance(); // Output: 1000
  return 0;
}
