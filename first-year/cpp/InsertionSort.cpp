#include<iostream>
using namespace std;
void sort(int[],int,int);
int main (){
	int size=8;
	int arr[]={14,33,27,10,35,19,42,44};
	int i,j;
	for (i=1;i<size;i++){
		sort(arr,i-1,arr[i]);
		for(j=0;j<size;j++)
		cout<<arr[j]<<" ";
		cout<<"\n";
	}
	return 0;
}
void sort(int arr[],int index,int key){
	//while(index>=0){
		//int temp=index,i;
		for(int i=index;i>=0;i--){
			/*while(arr[index]>=key){
			arr[index+1]=arr[index]; //shifting towards right
			index-=1;
			if(index==-1)
			break;
			}*/
			if(arr[i]<key){
				arr[i+1]=key;
				break;
			}
			if(arr[i]>=key&&i==0){
				arr[i+1]=arr[i];
				arr[i]=key;
			}
			else if(arr[i]>=key)
				arr[i+1]=arr[i];
	//}	
	}
}
