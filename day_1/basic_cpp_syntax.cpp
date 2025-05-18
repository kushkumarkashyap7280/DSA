// Basic C++ Program with Detailed Explanations

// Header file for input/output operations
#include <iostream>

// Using standard namespace (contains cout, cin, endl, etc.)
using namespace std;

// Main function - program execution starts here
int main() {
    // Variables declaration and initialization
    int number = 10;           // Integer type
    float decimal = 10.5;      // Floating point number
    char character = 'A';      // Single character
    bool isTrue = true;        // Boolean value
    
    // Output to console
    cout << "=== Basic C++ Data Types ===" << endl;
    cout << "Integer: " << number << endl;      // Prints: Integer: 10
    cout << "Float: " << decimal << endl;       // Prints: Float: 10.5
    cout << "Character: " << character << endl; // Prints: Character: A
    cout << "Boolean: " << isTrue << endl;     // Prints: Boolean: 1
    
    // Input from user
    int userNumber;
    cout << "\nEnter a number: ";
    cin >> userNumber;
    
    // Conditional statement (if-else)
    if (userNumber > 10) {
        cout << "Number is greater than 10" << endl;
    } else if (userNumber == 10) {
        cout << "Number is equal to 10" << endl;
    } else {
        cout << "Number is less than 10" << endl;
    }
    
    // Loop demonstration (for loop)
    cout << "\nCounting from 1 to 5: ";
    for (int i = 1; i <= 5; i++) {
        cout << i << " ";
    }
    cout << endl;
    
    // Loop demonstration (while loop)
    cout << "Counting down from 5: ";
    int count = 5;
    while (count > 0) {
        cout << count << " ";
        count--;
    }
    cout << endl;
    
    // Basic arithmetic operations
    cout << "\n=== Basic Arithmetic ===" << endl;
    cout << "Addition: " << 5 + 3 << endl;        // 8
    cout << "Subtraction: " << 5 - 3 << endl;     // 2
    cout << "Multiplication: " << 5 * 3 << endl;  // 15
    cout << "Division: " << 5.0 / 3.0 << endl;    // 1.666...
    cout << "Modulus: " << 5 % 3 << endl;         // 2
    
    return 0; // Program ends
}
