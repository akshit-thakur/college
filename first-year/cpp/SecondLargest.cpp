#include<iostream>
using namespace std;
int main(){
	int* arr;
	int n,i;
	cout<<"Enter size of elements:\n";
	cin>>n;
	cout<<"Enter "<<n<<" elements:\n";
	arr=new int[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	cout<<"The array is:\n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	for(i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]<arr[j]){
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;			
			}
		}
	}
	cout<<"\nThe second largest number is: "<<arr[1]<<"\n";
}
