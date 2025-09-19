#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Array before rearrangement: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    bool hasNeg = false;
    for (int i = 0; i < n; i++) if (arr[i] < 0) hasNeg = true;

    if (!hasNeg) {
        cout << "No negative numbers found" << endl;
    } else {
        int left = 0, right = n - 1;
        while (left < right) {
            if (arr[left] < 0) left++;
            else if (arr[right] >= 0) right--;
            else {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
        cout << "Array after moving negatives: ";
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}
