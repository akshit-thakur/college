#include<iostream.h>
using namespace std;
class Max{
	int a,b;
	public:
	Max(int x,int y){
		a=x;
		b=y;
	}
	friend int max(Max);
};
int max(Max m){
	if(m.a>m.b) return m.a;
	else 	return m.b;
}
int main(){
	int a,b;
	cout<<"Enter 2 numbers:\n";
	cin>>a>>b;
	Max obj(a,b);
	cout<<"The greater number is: "<<max(obj);
	return 0;
}
