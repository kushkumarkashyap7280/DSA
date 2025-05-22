#include <iostream>
#include <iomanip> // for setw
using namespace std;

int main()
{
  cout << "---------- 2D Array Basics ----------\n\n";

  // 1. Different ways to initialize 2D arrays
  cout << "1. Initialization Methods:\n";

  // Method 1: Default initialization
  int arr1[3][4]; // Contains garbage values
  cout << "Default initialized array (garbage values):\n";
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cout << setw(4) << arr1[i][j] << " ";
    }
    cout << endl;
  }

  // Method 2: Zero initialization
  int arr2[3][4] = {0};
  cout << "\nZero initialized array:\n";
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cout << setw(4) << arr2[i][j] << " ";
    }
    cout << endl;
  }

  // Method 3: Partial initialization
  int arr3[3][4] = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12}};
  cout << "\nFully initialized array:\n";
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      cout << setw(4) << arr3[i][j] << " ";
    }
    cout << endl;
  }

  // 2. Finding dimensions of 2D array
  cout << "\n2. Array Dimensions:\n";
  int rows = sizeof(arr3) / sizeof(arr3[0]);       // number of rows
  int cols = sizeof(arr3[0]) / sizeof(arr3[0][0]); // number of columns
  cout << "Number of rows: " << rows << endl;
  cout << "Number of columns: " << cols << endl;
  cout << "Total elements: " << rows * cols << endl;

  // int  total_elements = rows * columns;

  // accessing elements of 2D array
  // cout << "m[0][0] = " << m[0][0] << endl;

  // to  demonstrate 2D array , input and output how it works
  //  2D array
  int p, q;
  cout << "enter no. of rows :";
  cin >> p;
  cout << "\n enter no. of columns :";
  cin >> q;
  int m[p][q] = {0};
  cout << " your 2d array  is :" << endl;
  for (int i = 0; i < p; i++)
  {
    for (int j = 0; j < q; j++)
    {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
  cout << "\n ------------- enter your 2d array ---------" << endl;
  for (int i = 0; i < p; i++)
  {
    for (int j = 0; j < q; j++)
    {
      cout << "enter " << i << " " << j << " :" << endl;
      cin >> m[i][j];
    }
  }

  cout << " your 2d array  is :" << endl;
  for (int i = 0; i < p; i++)
  {
    for (int j = 0; j < q; j++)
    {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }

  // 3. Common operations on 2D arrays
  cout << "\n3. Common Operations:\n";

  //  find a specific element
  int element_to_find;
  cout << "Enter element to find: ";
  cin >> element_to_find;
  bool found = false;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (arr3[i][j] == element_to_find)
      {
        cout << "Element found at position [" << i << "][" << j << "]\n";
        found = true;
        break;
      }
    }
    if (found)
      break;
  }
  

  // a. Finding max element
  int max_element = arr3[0][0];
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (arr3[i][j] > max_element)
      {
        max_element = arr3[i][j];
      }
    }
  }
  cout << "Maximum element: " << max_element << endl;

  // b. Sum of all elements
  int sum = 0;
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      sum += arr3[i][j];
    }
  }
  cout << "Sum of all elements: " << sum << endl;

  // c. Row-wise sum
  cout << "Row-wise sums:\n";
  for (int i = 0; i < rows; i++)
  {
    int row_sum = 0;
    for (int j = 0; j < cols; j++)
    {
      row_sum += arr3[i][j];
    }
    cout << "Row " << i << ": " << row_sum << endl;
  }

  // d. Column-wise sum
  cout << "Column-wise sums:\n";
  for (int j = 0; j < cols; j++)
  {
    int col_sum = 0;
    for (int i = 0; i < rows; i++)
    {
      col_sum += arr3[i][j];
    }
    cout << "Column " << j << ": " << col_sum << endl;
  }

  // 4. Dynamic input example
  cout << "\n4. Dynamic Input Example:\n";
  int p, q;
  cout << "Enter number of rows: ";
  cin >> p;
  cout << "Enter number of columns: ";
  cin >> q;

  // Create and initialize array
  int dynamic_arr[p][q];

  // Input values
  cout << "\nEnter array elements:\n";
  for (int i = 0; i < p; i++)
  {
    for (int j = 0; j < q; j++)
    {
      cout << "Enter element [" << i << "][" << j << "]: ";
      cin >> dynamic_arr[i][j];
    }
  }

  // Display array in matrix format
  cout << "\nEntered array in matrix format:\n";
  for (int i = 0; i < p; i++)
  {
    for (int j = 0; j < q; j++)
    {
      cout << setw(4) << dynamic_arr[i][j] << " ";
    }
    cout << endl;
  }

  // 5. Memory layout explanation
  cout << "\n5. Memory Layout:\n";
  cout << "Base address of array: " << &arr3[0][0] << endl;
  cout << "Address of first row: " << &arr3[0] << endl;
  cout << "Address of second row: " << &arr3[1] << endl;
  cout << "Size of one row: " << sizeof(arr3[0]) << " bytes\n";
  cout << "Size of one element: " << sizeof(arr3[0][0]) << " bytes\n";

  return 0;
}