#include<iostream>
#define INFY 12345678;
using namespace std;
int* a;
int partition(int m,int p){
	int i=m,j=p;
	int v=a[m];
	do{
		do{ i+=1; }while(a[i]<v);
		do{ j-=1; }while(a[j]>v);			
		if(i<j){
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<=j);
	a[m]=a[j];
	a[j]=v;
	return j;
}
void select(int n,int k){
	int low=0;
	int up=n+1;
	a[n]=INFY;
	do{
		int j=partition(low,up);
		if(k==j)
		return;
		else if(k<j)
		up=j;
		else
		low=j+1;
	}while(true);
}
int main(){
	int n,i;
	cout<<"Enter the array size: ";
	cin>>n;
	a=new int[n+1];
	cout<<"Enter the array:\n";
	for(i=0;i<n;i++)
	cin>>a[i];
	for(i=0;i<n;i++)
	select(n,i);
	cout<<"The array after sorting is: \n";
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<"\n";
	return 0;
}
