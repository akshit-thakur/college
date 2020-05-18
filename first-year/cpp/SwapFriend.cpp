#include<iostream>
using namespace std;
class Swap{
   int x,y;
   public:
   Swap(int a,int b){
      x=a;
      y=b;
   }
   friend void doSwap(Swap &s);
   void show(){
	 cout<<x<<"\n"<<y<<"\n";
   }
};
void doSwap(Swap &s){
   int t=s.x;
   s.x=s.y;
   s.y=t;	
}
int main(){
    int a,b;
    cout<<"Enter 2 numbers: \n";
    cin>>a>>b;
	Swap obj(a,b);
    cout<<"Before swapping,the values are: \n";
	obj.show();
    doSwap(obj);
    cout<<"After swapping,the values are: \n";
    obj.show();
    return 0;
}
