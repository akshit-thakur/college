#include<iostream>
using namespace std;
class Time{
	int hr,min;
	public:
	Time(){}
	Time(int m){
		hr=m/60;
		min=m%60;
	}
	void display(){
		cout<<hr<<" hours and "<<min<<" minutes.\n";
	}
};
int main(){
    Time obj;
	int m=200;
    obj=m;
    cout<<m<<" minutes is ";
    obj.display();
	return 0;
}
