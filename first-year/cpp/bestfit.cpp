#include<iostream>
using namespace std;
int main(){
	int i,n;
	float m,b,sumx=0,sumy=0,sumxy=0,sumxx=0;
	float* x;
	float* y;
	cout<<"Enter number of observations: \n";
	cin>>n;
	x=new float[n];
	y=new float[n];	
	for(i=0;i<n;i++){
		cout<<"Enter x: ";
		cin>>x[i];
		cout<<"Enter y: ";
		cin>>y[i];
		//do stuff
		sumxy+=(x[i]*y[i]);
		sumx+=x[i];
		sumy+=y[i];
		sumxx+=(x[i]*x[i]);
	}
	m=((n*sumxy)-(sumx*sumy))/((n*sumxx)-(sumx*sumx));
	b=(sumy-m*sumx)/n;
	cout<<"m: "<<m<<"\n"<<"b: "<<b<<"\n";
	return 0;
}
