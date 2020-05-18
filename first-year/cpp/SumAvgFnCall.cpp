#include<iostream>
using namespace std;
class Num{
	int x,y;
	public:
	Num(int a,int b){
		x=a;
		y=b;
	}
	int sum(){
		return x+y;
	}
	float avg();
}
inline float Num::avg(){
	return (x+y)/2.0;
}
int main(){
	int m,n;
	cout<<"Enter 2 numbers\n";
	cin>>m>>n;
	Num obj(m,n);
	int sum=obj.sum();
	float avg=obj.avg();
	cout<<"Sum  "<<sum<<"\n"<<"Average "<<avg;
	return 0;
}
