#include<iostream>
using namespace std;
class B;
class A{
	int a;
	public:
	void getData(int i){ a=i; }
	friend void display(A &,B &);
	friend void swap(A &,B &);
};
class B{
	int b;
	public:
	void getData(int i){ b=i; }
	friend void display(A&,B&);
	friend void swap(A &,B &);
};
void swap(A &x,B &y){
	int temp=x.a;
	x.a=y.b;
	y.b=temp;
}
void display(A &x,B &y){
	cout<<"a: "<<x.a<<" b: "<<y.b<<"\n";	
}
int main(){
	A a; B b;
	a.getData(100);
	b.getData(200);
	cout<<"Before swapping:\n";
	display(a,b);
	swap(a,b);
	cout<<"After swapping:\n";
	display(a,b);
	return 0;
}
