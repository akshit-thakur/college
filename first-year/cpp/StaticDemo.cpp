#include<iostream>
using namespace std;
class Test{
	static int count;
	int number;
	public:
	void get(int a){
		number=a;
		count++;
	}
	void getC(){
		cout<<count<<"\n";	
	}
};
int Test::count;
int main(){
	Test t1,t2,t3;
	t1.getC();
	t1.get(100);
	t2.getC();
	t2.get(200);
	t3.getC();
	t3.get(300);
	t3.getC();
	return 0;
}
