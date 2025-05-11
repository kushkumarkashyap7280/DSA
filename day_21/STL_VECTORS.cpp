#include <iostream>
#include <vector> // vecotr library
using namespace std;

int main() {
    // ================== VECTOR ==================
    // Definition: Dynamic array from STL that resizes automatically

    // Declaration and Initialization
    vector<int> vec1;                      // Empty vector
    vector<int> vec2 = {1, 2, 3, 4};       // Initializer list
    vector<int> vec3(5, 100);              // Five elements of value 100

    // Accessing elements
    cout << "Element at index 2: " << vec2[2] << endl;
    cout << "Element at index 3 (safe): " << vec2.at(3) << endl;
    cout << "First Element: " << vec2.front() << endl;
    cout << "Last Element: " << vec2.back() << endl;

    // Modifiers
    vec1.push_back(10);
    vec1.push_back(20);
    vec1.push_back(30);
    vec1.pop_back();                      // Removes last element

    // Insert and Erase
    vec2.insert(vec2.begin() + 2, 99);    // Insert 99 at index 2
    vec2.erase(vec2.begin() + 1);         // Erase element at index 1

    // Size, Capacity, Resize
    cout << "Size of vec2: " << vec2.size() << endl;
    cout << "Capacity of vec2: " << vec2.capacity() << endl;
    vec2.resize(6);                       // Resize to 6 elements (new are default-initialized)

    // Iterating through vector
    cout << "Elements of vec2: ";
    for (int x : vec2) cout << x << " ";
    cout << endl;

    // Using iterators
    cout << "Elements of vec3 using iterators: ";
    for (auto it = vec3.begin(); it != vec3.end(); ++it) cout << *it << " ";
    cout << endl;

    // Clear vector
    vec3.clear();
    cout << "Is vec3 empty? " << (vec3.empty() ? "Yes" : "No") << endl;

    return 0;
}
