#include<iostream>
using namespace std;

void disp(int* &a,int n){
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<"\n";
}

int partition(int* &a,int m,int p){
	int i=m; int j=p; int v=a[m];
    do{
        do{ i+=1; }while(a[i]<v);
        do{ j-=1; }while(a[j]>v);
        if(i<=j){
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }while(i<=j);
    a[m]=a[j];
    a[j]=v;
    return j;
}

void quickSort(int* &a,int low,int high){
	if(low<high){
		int j=partition(a,low,high+1);
		quickSort(a,low,j-1);
		quickSort(a,j+1,high);
	}
}


int main (){

	int n;
	cout<<"Enter the size of array: ";
	cin>>n;

	int* a=new int[n+1];

	cout<<"Enter the array:\n";	
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	a[n]=999999;
	
	cout<<"Array before quicksort:\n";
	disp(a,n);
	
	quickSort(a,0,n);
	
	cout<<"Array after quicksort:\n";
	disp(a,n);
	
	return 0;
}
