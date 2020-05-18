#include <iostream>
using namespace std;
class Base{
	public:
	int b;
	virtual void show(){
		cout<<"In base class, b: "<<b<<"\n";
	}
};
class Derived:public Base{
	int d=100;
	public:
	void show(){
		cout<<"In derived class, b: "<<b<<" and d: "<<d<<"\n";
	}
};
int main(){
	Base *bptr;
	Base objb;
	Derived objd;
	bptr=&objb;
	bptr->b=100;
	bptr->show();
	bptr=&objd;
	bptr->b=200;
	bptr->show();
	return 0;
}
