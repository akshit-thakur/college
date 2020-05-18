/**
12. Linear Search
COMPLETED
*/
#include<iostream>
using namespace std;
int main (){
	int i,n,item;
	int* arr;

	cout<<"Enter size of array: ";
	cin>>n;
	
	arr=new int[n];

	cout<<"\nEnter the array:\n";
	for( i=0; i<n ; i++)
		cin>>arr[i];
	
	cout<<"The array is:\n";
	for( i=0; i<n ; i++)
		cout<<arr[i]<<" ";
	cout<<"\n";

	cout<<"Enter the item you want to search:\n";
	cin>>item;

	for( i=0; i<n ; i++){
		if(arr[i] == item)
		break;
	}

	if(i == n)
	cout<<"Item not found\n";
	else
	cout<<"Found at "<<i+1<<"th location\n";

	return 0;
}
