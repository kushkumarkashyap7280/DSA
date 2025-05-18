#include <iostream>
using namespace std;

// Function to check voting eligibility
bool canVote(int age)
{
  return age >= 18;
}

// Function to check driving license eligibility
bool canDrive(int age)
{
  return age >= 16;
}

// Function to check if person is eligible for both
bool isAdult(int age)
{
  return age >= 18;
}

int main()
{
  int age;
  cout << "Enter your age: ";
  cin >> age;

  if (canVote(age))
  {
    cout << "You can vote!" << endl;
  }
  else
  {
    cout << "You cannot vote yet." << endl;
  }

  if (canDrive(age))
  {
    cout << "You can apply for a driving license!" << endl;
  }
  else
  {
    cout << "You cannot drive yet." << endl;
  }

  if (isAdult(age))
  {
    cout << "You are an adult!" << endl;
  }
  else
  {
    cout << "You are a minor." << endl;
  }

  return 0;
}
