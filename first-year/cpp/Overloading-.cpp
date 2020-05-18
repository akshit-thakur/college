#include<iostream>
using namespace std;
class Unary{
	int a,b,c,d;
	public:
	Unary(){
	}
	Unary(int w,int x,int y,int z){	
		a=w; b=x; c=y; d=z;
	}
	void show(){
		cout<<"a: "<<a<<"\n"
		<<"b: "<<b<<"\n"
		<<"c: "<<c<<"\n"
		<<"d: "<<d<<"\n";	
	}
	void operator -();
};
void Unary::operator -(){
	a=-a;
	b=-b;
	c=-c;
	d=-d;
}
int main(){
	int w,x,y,z;
	cout<<"Enter 4 values: \n";
	cin>>w>>x>>y>>z;
	Unary obj(w,x,y,z);
	obj.show();
	-obj;
	cout<<"Operator overloaded\n";
	obj.show();	
	return 0;
}
