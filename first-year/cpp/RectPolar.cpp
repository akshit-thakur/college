#include<iostream>
#include<math.h>
using namespace std;
class Polar;
class Rectangle{
	float x,y;
	public:
	Rectangle(){}
	Rectangle(float a,float b){ x=a; y=b; }
	float getX(){ return x; }
	float getY(){ return y; }
	friend void display(Rectangle&,Polar&);
};
class Polar{
	float r,t;
	public:
	Polar(){}
	Polar(Rectangle &c){
		r=sqrt(c.getX()*c.getX()+c.getY()*c.getY());
		t=atan(c.getY()/c.getX());	
	}
	friend void display(Rectangle&,Polar&);
	/*Polar operator =(Rectangle &c){
		Polar temp;
		temp.r=getR();
		temp.t=atan(c.getY()/c.getX());
		return temp;	
	}*/
};
void display(Rectangle &c,Polar &p){
	cout<<"Cartesian coordinates: ";
	cout<<"("<<c.x<<","<<c.y<<")\n";
	cout<<"Polar coordinates: ";
	cout<<"("<<p.r<<","<<p.t<<")\n";
}
int main(){
	float x,y;
	cout<<"Enter x and y: \n";
	cin>>x>>y;
	Rectangle r(x,y);
	Polar p(r),p1;
	//constructor method	
//	cout<<"Enter x and y: \n";
	//cin>>x>>y;
	//Rectangle r1(x,y);
	//p1=r1;	
	display(r,p);
	//display(r1,p1);
	return 0;
}
