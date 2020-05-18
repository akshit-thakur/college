#include<iostream>
using namespace std;
class Test{
	int a,b;
	public:
	Test(){
		a=10; b=20;
	}
	operator int(){
		return a;
	}
};
int main(){
    Test obj;
    int x=obj;
    cout<<x<<"\n";
	return 0;
}
