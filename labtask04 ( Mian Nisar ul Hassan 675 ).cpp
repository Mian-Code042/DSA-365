#include <iostream>
using namespace std;

int main() {
    int arr[3][3], t[3][3];
    int i, j;

    cout << "Enter 9 numbers for 3x3 array: " << endl;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    // transpose

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            t[j][i] = arr[i][j];
        }
    }

    cout << "Transpose matrix: " << endl;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }

    // sum of first row
    
    int sum = 0;
    for (j = 0; j < 3; j++) {
        sum = sum + t[0][j];
    }
    cout << "Sum of first row = " << sum << endl;

    return 0;
}
