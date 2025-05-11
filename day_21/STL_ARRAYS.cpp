
// ARRAYS

// array is a container that encapsulates fixed-size arrays. Unlike built-in arrays, it provides many helpful methods and safety (like bounds checking with .at()).

#include <iostream>
#include <array>
using namespace std;

int main() {
    // Declaration and Initialization
    array<int, 5> arr1;                     // Uninitialized
    array<int, 5> arr2 = {1, 2, 3, 4, 5};   // Fully initialized
    array<int, 5> arr3 = {10, 20};          // Partially initialized, rest will be 0
    array<int, 5> arr4 = {};                // All elements initialized to 0

    // Accessing elements
    cout << "Element at index 2: " << arr2[2] << endl;
    cout << "Element at index 3 (safe): " << arr2.at(3) << endl;
    cout << "First Element: " << arr2.front() << endl;
    cout << "Last Element: " << arr2.back() << endl;

    // Size and empty
    cout << "Size of array: " << arr2.size() << endl;
    cout << "Is array empty? " << (arr2.empty() ? "Yes" : "No") << endl;

    // Filling array
    array<int, 5> fillArr;
    fillArr.fill(7);
    cout << "Filled array: ";
    for (int x : fillArr) cout << x << " ";
    cout << endl;

    // Iterating using iterators
    cout << "Iterating arr2 with iterators: ";
    for (auto it = arr2.begin(); it != arr2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Range-based loop
    cout << "Iterating arr2 with range-based loop: ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}
