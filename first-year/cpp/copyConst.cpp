#include<iostream>
using namespace std;
class Tri{
	int a,b;
	public:
	Tri(int x,int y){
		a=x;
		b=y;	
	}
	Tri(Tri &obj){
		a=obj.a;
		b=obj.b;
	}
	void disp(){
		cout<<"Area: "<<(a*b/2)<<"\n";	
	}
};
int main(){
	Tri t(10,5);
	Tri t1(t);
	Tri t2=t1;
	t.disp();
	t1.disp();
	t2.disp();
	return 0;
}
