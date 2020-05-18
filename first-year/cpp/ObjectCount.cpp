#include<iostream>
#include<iomanip>
using namespace std;
class Test{
	int a,b,c;
	static int count;
	public:
	Test(){
		a=0;
		b=0;
		c=0;
		count+=1;
	}
	Test(int x){
		a=x;
		b=x;
		c=x;
		count+=1;
	}
	Test(int x,int y){
		a=x;
		b=y;
		c=y;
		count+=1;
	}
	Test(int x,int y,int z){
		a=x;
		b=y;
		c=z;
		count+=1;
	}
	static void showCount(){
		cout<<"Total objects: "<<count<<endl;
	}
};
int Test::count=0;
int main(){
	Test obj,obj1(2),obj2(3,4),obj3(1,5,6);
	Test::showCount();
	return 0;
}
