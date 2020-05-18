#include<iostream.h>
#include<conio.h>
class Mean{
	int a,b;
	public:
	Mean(int x,int y){
		a=x;
		b=y;
	}
	friend float mean(Mean);
};
float mean(Mean n){
	return (n.a+n.b)/2.0;
}
int main(){
	clrscr();
	int x,y;
	cout<<"Enter 2 numbers:\n";
	cin>>x>>y;
	Mean obj(x,y);
	cout<<"The mean is: "<<mean(obj);
	getch();
	return 0;
}