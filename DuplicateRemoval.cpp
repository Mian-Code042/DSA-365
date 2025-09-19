#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Original array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int index = 0;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < index; j++) {
            if (arr[i] == arr[j]) {
                found = true;
                break;
            }
        }
        if (!found) arr[index++] = arr[i];
    }

    if (index == n) {
        cout << "No duplicates found" << endl;
    } else {
        cout << "Array after removing duplicates: ";
        for (int i = 0; i < index; i++) cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}
