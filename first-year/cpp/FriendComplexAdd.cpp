#include<iostream>
using namespace std;
class Complex{
	int real,imag;
	public:
	void getComplex(){
		cout<<"Enter real and imaginary part: \n";
		cin>>real>>imag;	
	}
	void show(){
		cout<<real<<" +j"<<imag<<"\n";	
	}
	friend Complex sum(Complex &c1,Complex &c2){
		Complex temp;
		temp.real=c1.real+c2.real;
		temp.imag=c1.imag+c2.imag;
		return temp;	
	}
};		
int main(){
	Complex a,b,c;
	a.getComplex();
	b.getComplex();
	c=sum(a,b);
	a.show();
	b.show();
	c.show();
	return 0;
}
