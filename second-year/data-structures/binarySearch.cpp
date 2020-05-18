/**
13 Binary Search
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
	cout<<"Enter the array:\n";
	for( i=0; i<n ; i++)
		cin>>arr[i];
	
	cout<<"The array is:\n";
	for( i=0; i<n ; i++)
		cout<<arr[i]<<" ";
	cout<<"\n";
	/**sorting the array because binary search only works for sorted arrays*/
	for( i=0; i<n; i++){ //selection sort	
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}

	cout<<"Enter the item you want to search:\n";
	cin>>item;

	int visited=0;
	/*binary search*/	
	int start=0,end=n,mid;
	while(start<=end){
		mid=(start+end)/2;
		if(arr[mid] == item){
			cout<<"Item found at "<<mid+1<<"th location.\n";
			visited=1;
			break;		
		}
		else if(item < arr[mid])
		end-=1;
		else
		start+=1;
	}

	if(visited==0)
	cout<<"Not found\n";	
	
	
	return 0;
}
