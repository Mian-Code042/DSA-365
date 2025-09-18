#include <iostream>
using namespace std;

int main() {
    int n, target;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> target;

    int start = 0, sum = 0;
    bool found = false;

    for (int end = 0; end < n; end++) {
        sum += arr[end];
        while (sum > target && start < end) {
            sum -= arr[start];
            start++;
        }
        if (sum == target) {
            cout << "Subarray found from index " << start << " to " << end << endl;
            found = true;
            break;
        }
    }

    if (!found) cout << "No subarray with given sum" << endl;

    return 0;
}

