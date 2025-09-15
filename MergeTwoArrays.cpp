#include<iostream>
using namespace std;

int main() {
    int size;
    cout << "Enter size for 1st array: ";
    cin >> size;

    int* arr1 = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter element for arr1[" << i+1 << "]: ";
        cin >> arr1[i];
    }

    int siz;
    cout << "Enter size for 2nd array: ";
    cin >> siz;

    int* arr2 = new int[siz];
    for (int i = 0; i < siz; i++) {
        cout << "Enter element for arr2[" << i+1 << "]: ";
        cin >> arr2[i];
    }

    // Create merged array
    int* arr3 = new int[size + siz];

    // Copy arr1
    for (int i = 0; i < size; i++) {
        arr3[i] = arr1[i];
    }

    // Copy arr2
    for (int i = 0; i < siz; i++) {
        arr3[size + i] = arr2[i];
    }

    cout << "\nMerged Array elements: ";
    for (int i = 0; i < size + siz; i++) {
        cout << arr3[i] << " ";
    }

    // Free memory
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}
