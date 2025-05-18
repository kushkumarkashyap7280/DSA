#include <iostream>
using namespace std;

// Question 1: Write a program to check if a person is eligible for driving license
// Age should be >= 18 and should have passed the test (boolean)
bool isEligibleForLicense(int age, bool passedTest)
{
  if (age >= 18 && passedTest)
  {
    return true;
  }
  return false;
}

// Question 2: Write a grade calculator
// >= 90: A, >= 80: B, >= 70: C, >= 60: D, < 60: F
char calculateGrade(int marks)
{
  if (marks >= 90)
    return 'A';
  else if (marks >= 80)
    return 'B';
  else if (marks >= 70)
    return 'C';
  else if (marks >= 60)
    return 'D';
  return 'F';
}

int main()
{
  // Test cases
  cout << "Driving License Test Cases:" << endl;
  cout << "Age 19, Passed: " << isEligibleForLicense(19, true) << endl;
  cout << "Age 17, Passed: " << isEligibleForLicense(17, true) << endl;

  cout << "\nGrade Calculator Test Cases:" << endl;
  cout << "95 marks: " << calculateGrade(95) << endl;
  cout << "75 marks: " << calculateGrade(75) << endl;
  return 0;
}
