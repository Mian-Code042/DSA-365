#include <iostream>
using namespace std;
int binarySearch(int arr[],int n,int target){
    int left=0,right=n-1;
    bool isAscending=arr[0]<arr[n-1];
    while(left<=right){
        int mid=left+(right-left)/2;
        if(arr[mid]==target) return mid;
        if(isAscending){
            if(target<arr[mid]) right=mid-1;
            else left=mid+1;
        }else{
            if(target>arr[mid]) right=mid-1;
            else left=mid+1;
        }
    }
}
int main(){
    int arr1[]={4,3,4,5,9};
    int arr2[]={7,5,4,3,1};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    int target=4;
    int result1=binarySearch(arr1,n1,target);
    if(result1!=-1) cout<<"Element "<<target<<" found at index "<<result1<<" in ascending array \n";
    else cout<<"Element not found in ascending array.\n";
    int result2=binarySearch(arr2,n2,target);
    if(result2!=-1) cout<<"Element "<<target<<" found at index "<<result2<<" in descending array \n";
    else cout<<"Element not found in descending array.\n";
}