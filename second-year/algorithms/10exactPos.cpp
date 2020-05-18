#include<iostream>
using namespace std;

int item = 0;

bool search(int* &A,int size,int x){
	for(int i=0;i<size;i++){
		if(A[i]==x){
			item = i;
			return true;
		}
	}
	return false;
}

void disp(int* A,int n){
	for(int i=0;i<n;i++)
	cout<<A[i]<<" ";
	cout<<"\n";
}

int findLoc(int* &a,int m,int p){
	int i=m;
	int j=p-1;
	int v=a[item];
	while(i<j){
		while(a[i]<=v)
		i+=1;
		while(a[j]>v)
		j-=1;
		if(i<j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	search(a,m+p,v);
	a[item]=a[j];
	a[j]=v;
	return j;
}

/*void findLoc(int* &A,int size,int x){
	int count=0,i,original=-1;
	for(i=0;i<size;i++){
		if(A[i]<x)
		count+=1;
		else if(A[i]==x)
		original=i;  //original index of x before finding exact location
	}
	cout<<"Exact location of "<<x<<" is: "<<(count+1)<<"\n";
	//swap x with A[count]
	int temp=A[count];
	A[count]=A[original];
	A[original]=temp;
	//j is for the subpart of array having values>x
	int j=count+1;
	for(i=0;i<size;i++){
		if(A[i]!=x&&A[i]>x){
			while(size-1>j&&A[j]>x) //finds the index of number smaller than x in the right subpart
				j+=1;
			if(j<=size-1){
				temp=A[j];
				A[j]=A[i];
				A[i]=temp;
			}
			else j=size-1; //
		}
	}
	disp(A,size);
}*/

int main (){
	int n,i,num;
	
	//input
	cout<<"Enter size of array:\n";
	cin>>n;
	
	int* arr=new int[n];
	
	cout<<"Enter the array in any order:\n";
	for(i=0;i<n;i++)
	cin>>arr[i];
	
	cout<<"Enter the number you want exact location of: ";
	cin>>num;
	
	//output
	cout<<"The array is:\n";
	disp(arr,n);
	
	if(search(arr,n,num))
	cout<<"The exact location of the number is: "<<findLoc(arr,0,n)<<"\n";
	else
	cout<<"Number not found.\n";
	
	cout<<"The array after finding exact location is:\n";
	disp(arr,n);
	
	return 0;
}
