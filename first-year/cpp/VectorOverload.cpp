#include<iostream>
using namespace std;
const int size=3;
class Vector{
	int v[size];
	public:
	Vector();	//constructs null vector
	Vector(int* x);	//constructs vector from array
	friend Vector operator *(int a,Vector b);
	friend Vector operator *(Vector b,int a);
	friend istream &operator >>(istream&,Vector&);
	friend ostream &operator <<(ostream&,Vector&);
};
Vector::Vector(){
	for(int i=0;i<size;i++)
		v[i]=0;
}
Vector::Vector(int* x){
	for(int i=0;i<size;i++)
		v[i]=x[i];
}
Vector operator *(int a,Vector b){
	Vector c;
	for(int i=0;i<size;i++)
		c.v[i]=a*(b.v[i]);
	return c;
}
Vector operator *(Vector b,int a){
	Vector c;
	for(int i=0;i<size;i++)
		c.v[i]=(b.v[i])*a;
	return c;
}
istream & operator >>(istream &din,Vector &b){
	for(int i=0;i<size;i++)
		din>>b.v[i];
	return (din);
}
ostream & operator <<(ostream &dout,Vector &b){
	dout<<"("<<b.v[0];
	for(int i=1;i<size;i++)
		dout<<" , "<<b.v[i];
	dout<<")";
	return (dout);
}
int x[size]={2,4,6};
int main(){
	Vector m; Vector n=x;
	cout<<"Enter elements of Vector m \n";
	cin>>m;	//invokes operator >>() fn
	cout<<"\n"<<"m = "<<m<<"\n";
	Vector p,q;
	p=2*m;
	q=n*2;
	cout<<"\n";
	cout<<"p = "<<p<<"\n"; //invokes operator <<() fn
	cout<<"q = "<<q<<"\n";
	return 0;
}
