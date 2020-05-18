#include<iostream>
#include<ctime>
using namespace std;
int main (){
	int size=100000,i;
	/**cout<<"Enter size of array: ";
	cin>>size;*/
	int* arr=new int[size];
	//cout<<"Enter "<<size<<" elements: \n";
	for(i=0;i<size;i++)
		//cin>>arr[i];
		arr[i]=1000-i;
	int start_s=clock();
	for(i=0;i<size;i++){
		for(int j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j]=temp;
			}
		}
	}
	int stop_s=clock();
	/*cout<<"The array after insertion sort is: ";
	for(i=0;i<size;i++)
		cout<<arr[i]<<" ";
	cout<<"\n";*/
	cout<<"Time taken: "<<(stop_s-start_s)/double(CLOCKS_PER_SEC)*1000<<" milliseconds.\n";
	return 0;
}
