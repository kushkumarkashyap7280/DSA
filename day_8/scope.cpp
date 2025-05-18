#include <iostream>
using namespace std;

// Global variable - accessible throughout the program
int globalVar = 100;

// Global function
void printGlobal() {
    cout << "Global variable: " << globalVar << endl;
}

int main() {
    // Local variable to main
    int localVar = 50;
    
    {
        // Block scope
        int blockVar = 25;
        cout << "Block variable: " << blockVar << endl;
        cout << "Can access local: " << localVar << endl;
        cout << "Can access global: " << globalVar << endl;
    }
    
    // blockVar is not accessible here
    
    // Function scope demonstration
    for(int i = 0; i < 3; i++) {  // i is limited to for loop
        cout << i << " ";
    }
    // i is not accessible here
    
    return 0;
}
