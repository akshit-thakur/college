#include<iostream>
using namespace std;
int findMin(int* A,int i,int n,int min){
	if(i<n){
		if(A[i]<min)
			min=A[i];
		findMin(A,i+1,n,min);
	}
	else
	return min;
}
int main (){
	int n,i;
	cout<<"Enter n: ";
	cin>>n;
	int* arr=new int[n];
	cout<<"Enter array:\n";
	for(i=0;i<n;i++)
	cin>>arr[i];
	cout<<"The smallest number in the array is: "<<findMin(arr,1,n,arr[0])<<"\n";
	return 0;
}
