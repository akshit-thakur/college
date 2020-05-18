#include<iostream>
using namespace std;
class Product{
	int m,n;
	public:
	Product(){
	}
	Product(int p,int q){
		m=p;
		n=q;
	}
	int getM(){
		return m;
	}
	int getN(){
		return n;
	}
	void display(){
		cout<<"m : "<<m<<" n: "<<n<<"\n";
	}
};
class Item{
	int a,b;
	public:
	Item(){
	}
	Item(Product &r){
		a=r.getM();
		b=r.getN();
	}
	void display(){
		cout<<"a : "<<a<<" b: "<<b<<"\n";
	}
};
int main(){
    Item i;
    Product p(2,3);
    i=p;
    i.display();
    p.display();
	return 0;
}
