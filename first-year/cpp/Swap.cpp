#include<iostream>
using namespace std;
void swap(int a,int b);
/*void swap(int &a,int &b);
int main(){
	int m=10,n=5;
	swap(m,n);
	cout<<m<<"\n"<<n<<"\n";	
	return 0;
}
void swap(int &a,int &b){
	cout<<a<<"\n"<<b<<"\n";
	int t=a;
	a=b;
	b=t;
}*/
int main()
{
 int m=10,n=5;
 swap(m,n);
 cout<<m<<"\n"<<n<<"\n";
 return 0;
}
void swap(int a,int b){
	cout<<a<<"\n"<<b<<"\n";
	int t=a;
	a=b;
	b=t;
}
