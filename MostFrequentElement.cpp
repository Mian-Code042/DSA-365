#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter the number of elements: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter " << size << " values:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int maxCount = 0;
    int mostFrequent = arr[0];

    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostFrequent = arr[i];
        }
    }

    cout << "Most frequent value: " << mostFrequent 
         << " (appears " << maxCount << " times)" << endl;

    delete[] arr;
    return 0;
}
