#include<iostream>
using namespace std;
int main(){
    int rows, cols;
    cout<<"Enter rows: ";
    cin>>rows;
    cout<<"Enter cols: ";
    cin>>cols;
    int** arr=new int*[rows];
    for(int i=0;i<rows;i++){
        arr[i]=new int[cols];
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<"Enter element for ["<<i<<"]["<<j<<"]: ";
            cin>>arr[i][j];
        }
    }
    int evenCount=0, oddCount=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(arr[i][j]%2==0) evenCount++;
            else oddCount++;
        }
    }
    int* evenArr=new int[evenCount];
    int* oddArr=new int[oddCount];
    int ek=0, ok=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(arr[i][j]%2==0) evenArr[ek++]=arr[i][j];
            else oddArr[ok++]=arr[i][j];
        }
    }
    cout<<"Even elements: ";
    for(int i=0;i<evenCount;i++){
        cout<<evenArr[i]<<" ";
    }
    cout<<"Odd elements: ";
    for(int i=0;i<oddCount;i++){
        cout<<oddArr[i]<<" ";
    }
}
