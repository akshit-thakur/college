#include<iostream>
using namespace std;
class Area{
	int l,b,area;
	public:
	Area(int x,int y){
		l=x;
		b=y;
	}
	Area(Area &r){
		l=r.l;
		b=r.b;
		area=l*b;
	}
	void display(){
		cout<<"Length: "<<l<<"\n"
		 <<"Breadth: "<<b<<"\n"
		 <<"Area: "<<area<<"\n";
	}
};
int main(){
	int x,y;
	cout<<"Enter length and breadth: ";
	cin>>x>>y;
	Area a(x,y);
	Area b(a);
	b.display();
	return 0;
}