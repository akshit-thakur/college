#include<iostream>
using namespace std;
//template<class T>
template<class X,class Y>
/*class Sum{
	T a,b;
	public:
	T(T x,T y){
		a=x;
		b=y;
	}
	T sums(){
		T s;
		s=a+b;
		return s;
	}
};*/
X sum(X x,Y y){
	return x+y;
}
int main(){
	/**Sum<int>obj(23,45);
	Sum<double>obj1(4.5,12.5);*/
	cout<<sum(34,22)<<"\n";
	cout<<sum('A','0')<<"\n";
	cout<<sum(12.4,34.6)<<"\n";
}
