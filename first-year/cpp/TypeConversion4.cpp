#include<iostream>
using namespace std;
class Item{
	int a,b;
	public:
	void assign(int x,int y){
		a=x;
		b=y;
	}
	void display(){
		cout<<"a: "<<a<<" b: "<<b<<"\n";
	}
};
class Product{
	int m,n;
	public:
	Product(){
		m=1; n=2;
	}
	operator Item(){
		Item temp;
		temp.assign(m,n);
		return temp;
	}
	void display(){
		cout<<"m: "<<m<<" n: "<<n<<"\n";
	}
};
int main(){
    Product p;
	Item i;
	i=p;
	i.display();
	p.display();
	return 0;
}
