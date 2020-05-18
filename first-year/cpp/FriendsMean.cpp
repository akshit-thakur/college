#include<iostream>
using namespace std;
class B;
class A{
	int x;
	public:
	A(int a){
		x=a;
	}
	friend void mean(A& a,B& b);
};
class B{
	int y;
	public:
	B(int b){
		y=b;
	}
	friend void mean(A& a,B& b);
};
void mean(A& a,B& b){
	cout<<"Their mean is: "<<((a.x+b.y))/2.0<<"\n";
}	
int main(){
	int m,n;
	cout<<"Enter 2 numbers:\n";
	cin>>m>>n;
	A a(m);
	B b(n);
	mean(a,b);
	return 0;
}
