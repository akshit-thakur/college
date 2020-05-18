#include<iostream>
using namespace std;
class Demo{
	int a,b;
	void getData(){
		cout<<"Enter a and b \n";
		cin>>a>>b;
	}
	void putData(){
		cout<<"a= "<<a<<"\n"<<"b= "<<b<<"\n";
	}
	public:
	void call(){
		getData();
		putData();
	}
};
int main(){
    Demo obj;
    obj.call();
    return 0;
}
