#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Array before moving zeros: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    bool hasZero = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            hasZero = true;
            break;
        }
    }

    if (!hasZero) {
        cout << "No zero found in array. Nothing to move!" << endl;
    } else {
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                arr[index++] = arr[i];
            }
        }
        while (index < n) {
            arr[index++] = 0;
        }
        cout << "Array after moving zeros: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}
