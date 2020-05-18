#include<iostream>
#include<cmath>
using namespace std;
template<class T>
class Abs{
	T a;
	public:
	Abs(T x){
		a=x;	
	}
	void show(){
		cout<<"Before : "<<a<<"\n";
		cout<<"After : "<<abs(a)<<"\n"; 
	}
	void abso(T x){
		cout<<"Before : "<<x<<"\n";
		cout<<"After : "<<abs(x)<<"\n"; 		
	}
};
int main(){
	Abs<double> obj(-3.5);
	obj.show();
	obj.abso(-30);
	return 0;
}
