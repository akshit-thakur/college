#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
int count=0;
void binarySearch(int* A,int s,int e,int item){
	if(s<=e){
		count+=1;
		int m=(s+e)/2;
		if(A[m]==item)
		cout<<"Success. Found at "<<m<<"\n";
		else if(A[m]<item)
		binarySearch(A,m+1,e,item);
		else
		binarySearch(A,s,m-1,item);
	}
	else cout<<"Failure\n";
}

int main (){
	int n=1,i;
	srand(time(0));
	while(n<128){
	
		int* arr=new int[n];
		
		for(i=0;i<n;i++)
			arr[i]= (rand()%(((i+1)*10-(i)*10))+ (i*10));
		int q=6554532;
		
		/*cout<<"The array is:\n";
		for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
		cout<<"\n";*/
		
		binarySearch(arr,0,n,q);
		
		cout<<"Number of iterations for n = "<<n<<" : "<<count<<"\n";
		
		count=0;
		
		delete arr;
		
		n*=2;
	}
	return 0;
}
