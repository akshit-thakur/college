#include<iostream>
#include<cmath>
using namespace std;
int main(){
	cout.fill('*');
	cout.setf(ios::left,ios::adjustfield);
	cout.width(10);
	cout<<"VALUE";
	cout.setf(ios::right,ios::adjustfield);
	cout.width(15);
	cout<<"SQRT OF VALUE"<<"\n";
	cout.fill('.');
	cout.precision(4);
	cout.setf(ios::showpoint);
	cout.setf(ios::showpos);
	cout.setf(ios::fixed,ios::floatfield);
	for(int i=1;i<=6;i++){
		cout.setf(ios::internal,ios::adjustfield);
		cout.width(5);
		cout<<i;
		cout.setf(ios::internal,ios::adjustfield);
		cout.setf(ios::right,ios::adjustfield);
		cout.width(20);
		cout<<sqrt(i)<<"\n";	
	}
	//floatfield changed
	cout.setf(ios::scientific,ios::floatfield);
	cout<<"\nSQRT(100) = "<<sqrt(100)<<"\n";

	return 0;
}
