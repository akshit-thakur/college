#include<iostream>
using namespace std;
class Test{
	int a,b,c;
	public:
	Test(){}
	friend istream &operator >>(istream&,Test&);
	friend ostream &operator <<(ostream&,Test&);
};
istream &operator >>(istream &din,Test &r){
	cin>>r.a>>r.b>>r.	c;
	return din;
}
ostream &operator <<(ostream &dout,Test &r){
	cout<<r.a<<" "<<r.b<<" "<<r.c<<"\n";	
	return dout;
}
int main(){
	Test obj;
	cout<<"Enter 3 values: ";	
	cin>>obj;
	cout<<obj;
	return 0;
}
