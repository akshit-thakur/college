#include<iostream.h>
#include<conio.h>
class Square{
	int a;
	public:
	Square(int n){
	    a=n;
	}
	int square(){
	    return a*a;
	}
	int square1();
};
inline int Square::square1(){
	return a*a;
}
int main(){
	clrscr();
	int n;
	cout<<"Enter a number: ";
	cin>>n;
	Square obj(n);
	cout<<"Square of "<<n<<" is "<<obj.square()<<"\n";
	cout<<"Square of "<<n<<" is "<<obj.square1()<<"\n";
	getch();
	return 0;
}
