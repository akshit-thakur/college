#include<iostream>
using namespace std;

//displays the array
void disp(int* A,int size){
	for(int i=0;i<size;i++)
	cout<<A[i]<<" ";
	cout<<"\n";
}

/*does selection sort by taking A[index] to be minimum 
and selecting the minimum by comparing A[index] with 
elements of array*/
void selSelection(int* A,int size,int index){
	int s=index;
	for( int i=index+1; i<size; i++){
		if( A[i]<A[s])
		s=i;
	}
	int temp=A[s];
	A[s]=A[index];
	A[index]=temp;
}


int main (){
	int* arr; int n; int i;
	
	//input
	cout<<"Enter the size of array:\n";
	cin>>n;
	cout<<"Enter the array:\n";
	for(i=0;i<n;i++)
	cin>>arr[i];
	
	//output
	cout<<"The array is:\n";
	disp(arr,n);
	
	for(i=0;i<n;i++)
		selSelection(arr,n,i);
	
	cout<<"The sorted array is:\n";
	disp(arr,n);
	
	return 0;
}

// 24/01/2019
