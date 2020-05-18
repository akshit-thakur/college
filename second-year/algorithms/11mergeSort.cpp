#include<iostream>
using namespace std;

int* a;
int* c;

void disp(int size){
	for( int i=0; i<size; i++)
		cout<<a[i]<<" ";
	cout<<"\n";
}

void merge(int low,int mid,int high){

	int h=low;
	int i=low;
	int j=mid+1;
	while(( h<=mid && j<=high )){
	
		if(a[h] <= a[j]){
			c[i] = a[h];
			h+=1;
		}
		
		else{
			c[i] = a[j];
			j+=1;
		}
		i+=1;
	} 	 
	if(h>mid){
		for(int k=j;k<=high;k++,i++)
			c[i]=a[k];
		/*
		while(j<=high){
			c[i]=a[j];
			i+=1;
			j+=1;
		}*/
	}
	else{
		for(int k=h;k<=mid;k++,i++)
			c[i]=a[k];
		/*
		while(h<=mid){
			c[i]=a[h];
			i+=1;
			h+=1;
		}*/
	}
	for(i=low;i<=high;i++)
		a[i]=c[i];
}

void mergeSort(int low,int high){
	if(low<high){
		int mid= (low+high)/2;
		mergeSort(low,mid);
		mergeSort(mid+1,high);
		merge(low,mid,high);
	}
}



int main (){
	int n;

	cout<<"Enter the number of elements: ";
	cin>>n;
	
	a=new int[n];
	c=new int[n];
	
	cout<<"Enter the elements: ";
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	cout<<" The array before merge sort: \n";
	disp(n);
	
	mergeSort(0,n-1);
	
	cout<<" The array after merge sort: \n";
	disp(n);
	
	return 0;
}
