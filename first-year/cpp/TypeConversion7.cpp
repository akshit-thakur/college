#include<iostream>
using namespace std;
class Time{
	int hr,min;
	public:
	Time(int h,int m){
		hr=h;
		min=m;
	}
	int getTime(){
		return (hr*60)+min;
	}
	void display(){
		cout<<hr<<" hours and "<<min<<" minutes ";
	}
};
class Minute{
	int minute;
	public:
	Minute(){ }
	void display(){
		cout<<"= "<<minute<<" minutes.\n";
	}
	void operator =(Time &t){
		minute=t.getTime();
	}
};
int main(){
    Time t(3,40);
    Minute m;
    m=t;
	t.display();
	m.display();
	return 0;
}
