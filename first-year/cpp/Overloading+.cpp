#include<iostream>
using namespace std;
class Complex{
	float x,y;
	public:
	Complex(){}
	Complex(float a,float b){ x=a; y=b; }
	void display(){
		cout<<x<<" +j "<<y<<"\n";
	}
	Complex operator +(Complex c){
		Complex temp;
		temp.x=x+c.x;
		temp.y=y+c.y;
		return (temp);	
	}
};
int main(){
	Complex c1,c2,c3;
	c1=Complex(1.5,2.2);
	c2=Complex(2.5,6.8);
	c3=c1+c2;
	c1.display();
	c2.display();
	c3.display();
	return 0;
}
