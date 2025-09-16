#include <iostream>
using namespace std;

int main() {
    int arr[3][2];
    int i, j;

    cout << "Enter 6 numbers for 3x2 array: " << endl;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            cin >> arr[i][j];
        }
    }

    int val, count = 0;
    cout << "Enter number for searching : ";
    cin >> val;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            if (arr[i][j] == val) {
                cout << "Found at [" << i << "][" << j << "]" << endl;
                count = 1;
            }
        }
    }
    if (count == 0) {
        cout << "Not found" << endl;
    }

    cout << "Numbers greater than 5: ";
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            if (arr[i][j] > 5) {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }

    int sum = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            sum = sum + arr[i][j];
        }
    }
    cout << "Sum = " << sum << endl;

    return 0;
}
