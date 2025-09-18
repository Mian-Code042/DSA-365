#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements (only 0s and 1s): ";
    bool valid = true;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] != 0 && arr[i] != 1) {
            valid = false;
        }
    }
    if (!valid) {
        cout << "Error: Array should only contain 0s and 1s" << endl;
        return 0;
    }
    int left = 0, right = n - 1;
    while (left < right) {
        if (arr[left] == 0) {
            left++;
        } else if (arr[right] == 1) {
            right--;
        } else {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}

