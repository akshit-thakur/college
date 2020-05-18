#include<iostream>
using namespace std;
class Shape{
	protected:
	double a,b;
	public:
	void getData(){
		cout<<"Enter required dimensions: \n";
		cin>>a>>b;	
	}
	virtual void dispArea()=0;
};
class Rectangle:public Shape{
	protected:
	double area;
	public:
	void dispArea(){
		area=a*b;
		cout<<"Area: "<<area<<"\n";
	}
};
class Triangle:public Shape{
	protected:
	double area;
	public:
	void dispArea(){
		area=0.5*a*b;
		cout<<"Area: "<<area<<"\n";	
	}
};
int main(){
	Shape *sptr;
	Rectangle r;
	sptr=&r;
	cout<<"For rectangle...\n";
	sptr->getData();	
	Triangle t;
	sptr=&t;
	cout<<"For triangle...\n";
	sptr->getData();
	sptr=&r;
	cout<<"For rectangle...\n";
	sptr->dispArea();
	cout<<"For triangle...\n";
	sptr=&t;
	sptr->dispArea();
	return 0;
}
