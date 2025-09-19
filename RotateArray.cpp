#include <iostream>
using namespace std;

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter rotation step: ";
    cin >> k;

    cout << "Array before rotation: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    if (k % n == 0) {
        cout << "No rotation needed" << endl;
    } else {
        int rotated[n];
        for (int i = 0; i < n; i++) {
            rotated[(i + k) % n] = arr[i];
        }
        cout << "Array after rotation: ";
        for (int i = 0; i < n; i++) cout << rotated[i] << " ";
        cout << endl;
    }

    return 0;
}
