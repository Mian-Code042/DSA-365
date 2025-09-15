#include<iostream>
using namespace std;
int main(){
	int size;
	cout<<"Enter size:"<<endl;
	cin>>size;
	int* array=new int[size];
	for(int i=0;i<size;i++){
		cout<<"Enter element for "<<i+1<<" : ";
		cin>>array[i];
	}
	int n;
	cout<<"Enter number:";
	cin>>n;
	bool found=false;
	cout<<"Array elements : ";
   for(int i=0;i<size;i++){
   	if(array[i]>n){
		cout<<array[i]<<" ";
		found=true;
	}
}
if(!found){
	cout<<"All numbers are less";
}
	delete[] array;
}