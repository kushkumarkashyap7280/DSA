#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // 2D Vector Initialization Methods
  cout << "---------- 2D Vector Initialization ----------\n";

  // Method 1: Declaration with size
  vector<vector<int>> vec1(3, vector<int>(4, 0)); // 3x4 matrix initialized with 0
  cout << "Method 1 - Fixed size with initial value:\n";
  for (const auto &row : vec1)
  {
    for (int val : row)
      cout << val << " ";
    cout << endl;
  }

  // Method 2: Declaration with initializer list
  vector<vector<int>> vec2 = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9}};
  cout << "\nMethod 2 - Initializer list:\n";
  for (const auto &row : vec2)
  {
    for (int val : row)
      cout << val << " ";
    cout << endl;
  }

  // Method 3: Dynamic creation
  cout << "\n---------- Dynamic 2D Vector Creation ----------\n";
  int rows, cols;
  cout << "Enter number of rows: ";
  cin >> rows;
  cout << "Enter number of columns: ";
  cin >> cols;

  vector<vector<int>> vec3(rows, vector<int>(cols));

  // Input values
  cout << "\nEnter elements:\n";
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      cout << "Enter element at position [" << i << "][" << j << "]: ";
      cin >> vec3[i][j];
    }
  }

  // Demonstrating Vector Methods
  cout << "\n---------- Vector Methods ----------\n";

  // 1. Size operations
  cout << "Number of rows: " << vec3.size() << endl;
  cout << "Number of columns in first row: " << vec3[0].size() << endl;

  // 2. Adding a new row
  cout << "\nAdding a new row...\n";
  vector<int> new_row(cols, 99);
  vec3.push_back(new_row);

  // 3. Adding a new column to each row
  cout << "Adding a new column...\n";
  for (auto &row : vec3)
  {
    row.push_back(88);
  }

  // 4. Removing last row
  cout << "Removing last row...\n";
  vec3.pop_back();

  // 5. Removing last column from each row
  cout << "Removing last column...\n";
  for (auto &row : vec3)
  {
    row.pop_back();
  }

  // 6. Checking if empty
  cout << "\nIs vector empty? " << (vec3.empty() ? "Yes" : "No") << endl;

  // 7. Resizing
  cout << "Resizing to 2x2...\n";
  vec3.resize(2);
  for (auto &row : vec3)
  {
    row.resize(2);
  }

  // 8. Clear entire vector
  cout << "Clearing vector...\n";
  vec3.clear();
  cout << "Is vector empty after clear? " << (vec3.empty() ? "Yes" : "No") << endl;

  // Creating a new vector for more operations
  vector<vector<int>> vec4 = {{1, 2}, {3, 4}};

  // 9. Accessing elements
  cout << "\n---------- Element Access Methods ----------\n";
  cout << "First element: " << vec4.front()[0] << endl;
  cout << "Last element of last row: " << vec4.back().back() << endl;

  // 10. Using at() for safe access
  try
  {
    cout << "Using at() for access: " << vec4.at(0).at(0) << endl;
    cout << "Trying to access out of bounds..." << endl;
    cout << vec4.at(5).at(5); // This will throw an exception
  }
  catch (const out_of_range &e)
  {
    cout << "Exception caught: " << e.what() << endl;
  }

  // 11. Capacity operations
  cout << "\n---------- Capacity Operations ----------\n";
  cout << "Current capacity of first row: " << vec4[0].capacity() << endl;
  cout << "Current size of first row: " << vec4[0].size() << endl;

  // 12. Reserve space
  vec4[0].reserve(10);
  cout << "Capacity after reserve(10): " << vec4[0].capacity() << endl;

  // 13. Printing final vector
  cout << "\n---------- Final Vector State ----------\n";
  for (const auto &row : vec4)
  {
    for (int val : row)
      cout << val << " ";
    cout << endl;
  }

  return 0;
}
