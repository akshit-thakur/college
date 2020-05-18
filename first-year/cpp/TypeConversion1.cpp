#include<iostream>
using namespace std;
class Test{
	int x,y;
	public:
	Test(){	}
	Test(int a){
		x=a; y=3*a;
	}
	void display(){
		cout<<x<<" "<<y<<"\n";
	}
};
int main(){
    Test obj;
    obj=5;
    obj.display();
	return 0;
}
