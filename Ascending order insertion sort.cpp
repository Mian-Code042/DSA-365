#include <iostream>
using namespace std;
void insertion(int arr[], int n) {
    for (int i=1;i<n;i++) {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main() {
    int n;
    cout<<"Enter number of elements you want to enter in an array:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
    	cin>>arr[i];
	}
    int no=sizeof(arr)/sizeof(arr[0]);
    cout<<"Original array:";
    for(int i= 0;i<n;i++){
	cout << arr[i]<<" ";
}
    cout<<endl;
    insertion(arr, no);
    cout<<"Sorted Ascending array using insertion sort:";
    for (int i=0;i<n;i++) {
	cout<<arr[i]<<" ";
}
}

