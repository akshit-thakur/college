#include<iostream>
using namespace std;
int main(){
	int* arr;
	int n,i,search;
	cout<<"Enter size of elements:\n";
	cin>>n;
	cout<<"Enter "<<n<<" elements:\n";
	arr=new int[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	cout<<"The array is:\n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<"\nEnter the number you want to search: ";
	cin>>search;
	for(i=0;i<n;i++){
		if(arr[i]==search)
		break;
	}
	if(i==n)
	cout<<"Search Unsuccessful\n";
	else
	cout<<"Search Successful. "<<search<<" found at index "<<i+1<<"\n";
}
