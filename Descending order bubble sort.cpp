#include <iostream>
using namespace std;
void bubble(int arr[],int n) {
    for (int i=0;i<n-1;i++) {
        bool swapped=false;
        for (int j=0;j<n-i-1;j++) {
            if (arr[j]<arr[j+1]) {  
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=true;
            }
        }
        if(!swapped )break;
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
    bubble(arr, no);
    cout<<"Sorted Ascending array using bubble sort:";
    for (int i=0;i<n;i++) {
	cout<<arr[i]<<" ";
}
}