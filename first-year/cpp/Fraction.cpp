#include<iostream>
using namespace std;
class Fraction{
	int n,d;
	public:
	Fraction(){
		n=0;
		d=0;
	}
	Fraction(int a,int b){
		n=a;
		d=b;
	}
	void show(){
		cout<<n<<"/"<<d<<"\n";
	}
	void reduce(){
		for(int i=2;i<=n;i++){
			if(n%i==0&&d%i==0){
				n/=i;
				d/=i;
				i=1;
			}
		}
	}
	friend int operator ==(Fraction&,Fraction&);
	friend Fraction operator +(Fraction&,Fraction&);
	friend Fraction operator *(Fraction&,Fraction&);
};
int operator ==(Fraction& f,Fraction& s){
	f.reduce();
	s.reduce();
	if(f.n==s.n&&f.d==s.d)
	return 1;
	else
	return 0;
}
Fraction operator +(Fraction& f,Fraction& s){
	Fraction t;
	t.d=(f.d*s.d);
	t.n=(s.d*f.n)+(f.d*s.n);
	t.reduce();
	return t;	
}
Fraction operator *(Fraction& f,Fraction& s){
	Fraction t;
	t.d=(f.d*s.d);
	t.n=(f.n*s.n);
	t.reduce();
	return t;	
}
int main(){
	int a,b,c,d;
	cout<<"Enter first fraction numerator: ";
	cin>>a;
	cout<<"Enter first fraction denominator: ";
	cin>>b;
	cout<<"Enter second fraction numerator: ";
	cin>>c;
	cout<<"Enter second fraction denominator: ";
	cin>>d;
    Fraction f1(a,b),f2(c,d);
	if(f1==f2)
		cout<<"Equal fractions.\n";
	else
		cout<<"Not equal\n";
	Fraction f3,f4;
	f3=operator +(f1,f2);
	f3.show();
	f4=operator *(f1,f2);
	f4.show();
	return 0;
}
