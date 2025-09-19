#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    if (n < 2) {
        cout << "Array too small for second largest" << endl;
        return 0;
    }

    int largest = arr[0], second = -1e9;
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
        } else if (arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }
    }

    cout << "Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    if (second == -1e9) cout << "No second largest element found" << endl;
    else cout << "Second largest element: " << second << endl;

    return 0;
}
