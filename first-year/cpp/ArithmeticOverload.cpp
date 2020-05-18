#include<iostream>
using namespace std;
class Binary{
	int a,b;
	public:
	Binary(){}
	void getInput(){ 
		cout<<"Enter 2 numbers: \n"; cin>>a>>b; 
	}
	void show(){
		cout<<"a: "<<a<<"\n"<<"b: "<<b<<"\n";
	}
	Binary operator +(Binary o){
		Binary temp;
		temp.a=a+o.a;
		temp.b=b+o.b;
		return temp;
	}
	Binary operator -(Binary o){
		Binary temp;
		temp.a=a-o.a;
		temp.b=b-o.b;
		return temp;
	}
	Binary operator *(Binary o){
		Binary temp;
		temp.a=a*o.a;
		temp.b=b*o.b;
		return temp;
	}
	Binary operator /(Binary o){
		Binary temp;
		temp.a=a/o.a;
		temp.b=b/o.b;
		return temp;
	}
};
int main(){
	Binary b1,b2;
	b1.getInput(); b2.getInput();
	Binary s=b1+b2,d=b1-b2;
	Binary p=b1*b2,q=b1/b2;
	cout<<"First input: \n"; b1.show();
	cout<<"Second input: \n"; b2.show();
	cout<<"Sum :\n";	s.show();
	cout<<"Difference :\n";	d.show();	
	cout<<"Product: \n";	p.show();	
	cout<<"Quotient: \n";	q.show();
	return 0;
}
