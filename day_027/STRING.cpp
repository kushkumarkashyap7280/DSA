#include <iostream>
#include <string>
using namespace std;

int main()
{
  // 1. String Initialization Methods
  string str1 = "Hello";           // Method 1
  string str2("World");            // Method 2
  string str3(5, '*');             // Method 3: Creates "*****"
  string str4 = str1 + " " + str2; // Concatenation

  cout << "=== String Initialization ===" << endl;
  cout << "str1: " << str1 << endl;
  cout << "str2: " << str2 << endl;
  cout << "str3: " << str3 << endl;
  cout << "str4: " << str4 << endl
       << endl;

  // 2. Common String Methods
  cout << "=== String Methods ===" << endl;
  // Length and Size
  cout << "Length: " << str1.length() << endl;
  cout << "Size: " << str1.size() << endl;

  // Access Methods
  cout << "First char: " << str1.front() << endl;
  cout << "Last char: " << str1.back() << endl;
  cout << "At index 1: " << str1.at(1) << endl;

  // Modification Methods
  str1.append(" there"); // Append
  cout << "After append: " << str1 << endl;

  str1.insert(5, " "); // Insert
  cout << "After insert: " << str1 << endl;

  str1.erase(5, 1); // Erase
  cout << "After erase: " << str1 << endl;

  // Substring
  string sub = str1.substr(0, 5); // Get "Hello"
  cout << "Substring: " << sub << endl;

  // Find Operations
  size_t pos = str1.find("lo");
  cout << "Position of 'lo': " << pos << endl;

  // Compare Operations
  string s1 = "hello", s2 = "hello";
  cout << "Compare result: " << s1.compare(s2) << endl;

  // 3. Input Methods
  cout << "\n=== String Input ===" << endl;
  string userInput;
  cout << "Enter a string: ";
  // cin >> userInput;                    // For single word
  // getline(cin, userInput);            // For entire line

  // 4. Empty and Clear
  cout << "\n=== Empty and Clear ===" << endl;
  cout << "Is empty? " << userInput.empty() << endl;
  userInput.clear();
  cout << "After clear, is empty? " << userInput.empty() << endl;

  return 0;
}
