#include<iostream>
using namespace std;
class Binary{
	int a,b,c,d;
	public:
	Binary(){}
	Binary(int w,int x,int y,int z){	
		a=w; b=x; c=y; d=z;
	}
	void show(){
		cout<<"a: "<<a<<"\n"
		<<"b: "<<b<<"\n"
		<<"c: "<<c<<"\n"
		<<"d: "<<d<<"\n";	
	}
	friend Binary operator *(int n,Binary &);
};
Binary operator *(int n,Binary &r){
	Binary temp;	
	temp.a=(r.a)*n;
	temp.b=(r.b)*n;
	temp.c=(r.c)*n;
	temp.d=(r.d)*n;
	return temp;
}
int main(){
	int w,x,y,z;
	cout<<"Enter 4 values: \n";
	cin>>w>>x>>y>>z;
	Binary obj(w,x,y,z),obj1;
	obj.show();
	obj1=operator *(2,obj);
	cout<<"Operator overloaded\n";
	obj1.show();	
	return 0;
}
