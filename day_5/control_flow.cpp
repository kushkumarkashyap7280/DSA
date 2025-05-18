#include <iostream>
using namespace std;

int main() {
    // 1. Simple if-else
    int num = 10;
    if (num > 0) {
        cout << "Positive number" << endl;
    } else {
        cout << "Non-positive number" << endl;
    }

    // 2. if-else ladder
    int marks = 85;
    if (marks >= 90) {
        cout << "Grade A" << endl;
    } else if (marks >= 80) {
        cout << "Grade B" << endl;
    } else if (marks >= 70) {
        cout << "Grade C" << endl;
    } else {
        cout << "Grade D" << endl;
    }

    // 3. Nested if-else
    int age = 25;
    bool hasID = true;
    if (age >= 18) {
        if (hasID) {
            cout << "Can vote" << endl;
        } else {
            cout << "Need ID to vote" << endl;
        }
    } else {
        cout << "Too young to vote" << endl;
    }

    // 4. Switch statement
    char grade = 'B';
    switch (grade) {
        case 'A':
            cout << "Excellent" << endl;
            break;
        case 'B':
            cout << "Good" << endl;
            break;
        case 'C':
            cout << "Fair" << endl;
            break;
        default:
            cout << "Invalid grade" << endl;
    }

    // 5. Switch with multiple cases
    int day = 2;
    switch (day) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout << "Weekday" << endl;
            break;
        case 6:
        case 7:
            cout << "Weekend" << endl;
            break;
        default:
            cout << "Invalid day" << endl;
    }

    return 0;
}
