#include<iostream>
using namespace std;
class Time{
	int hr,min;
	public:
	Time(){}
	Time(int h,int m){
		hr=h;
		min=m;
	}
	void display(){
		cout<<hr<<" hours and "<<min<<" minutes ";
	}
	operator int(){
		return hr*60+min;
	}
};
int main(){
    Time obj(3,20);
    obj.display();
    int m=obj;
    cout<<"= "<<m<<" minutes.\n";
	return 0;
}
