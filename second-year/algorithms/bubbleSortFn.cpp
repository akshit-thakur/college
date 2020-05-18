#include<iostream>
using namespace std;

void selBubble(int* A,int size,int index){
	for(int i=0;i<size-index-1;i++){
		if(A[i]>A[i+1]){
			int temp=A[i];
			A[i]=A[i+1];
			A[i+1]=temp;
		}
	}
}

void disp(int* A,int size){
	for(int i=0;i<size;i++)
	cout<<A[i]<<" ";
	cout<<"\n";
}

int main (){
	int* arr; int n; int i;
	
	cout<<"Enter the size of array:\n";
	cin>>n;
	
	cout<<"Enter the array:\n";
	for(i=0;i<n;i++)
	cin>>arr[i];

	cout<<"The array is:\n";	
	disp(arr,n);
	

	for(i=0;i<n;i++)
	selBubble(arr,n,i);
	
	cout<<"The sorted array is:\n";	
	disp(arr,n);
	
	return 0;
}

// 24/01/2019
