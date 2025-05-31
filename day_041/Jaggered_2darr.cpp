#include <iostream>
using namespace std;

int main() {
    int m;
    cout << "Enter number of rows: ";
    cin >> m;

    // Create array of pointers for jagged array
    int** arr = new int*[m];
    int* rowSizes = new int[m]; // Store row sizes

    for (int i = 0; i < m; i++) {
        int n;
        cout << "Enter number of elements in row " << i << ": ";
        cin >> n;
        rowSizes[i] = n; // Store row size
        arr[i] = new int[n];

        for (int j = 0; j < n; j++) {
            cout << "Enter value for arr[" << i << "][" << j << "]: ";
            cin >> arr[i][j];
        }
    }

    cout << "\nYour Jagged Array:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < rowSizes[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Cleanup
    for (int i = 0; i < m; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] rowSizes;

    cout << "Done\n";
    return 0;
}
