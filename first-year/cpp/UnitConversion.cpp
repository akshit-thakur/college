#include<iostream>
using namespace std;
class DM;
class DB{
	float ft,in;
	public:
	DB(float f,float i){ ft=f; in=i; }
	void display(){
		cout<<ft<<" ft "<<in<<" in.\n";
	}
	void display(float a,float b){
		cout<<a<<" ft "<<b<<" in.\n";
	}
	friend void add(DB&,DM&,int);
};
class DM{
	float m,cm;
	public:
	DM(float a,float b){ m=a; cm=b; }
	void display(){
		cout<<m<<" m "<<cm<<" cm.\n";
	}
	void display(float a,float b){
		cout<<a<<" m "<<b<<" cm.\n";
	}
	friend void add(DB&,DM&,int);	
};
void add(DB &ob,DM &om,int ch){
	cout<<"Adding....\n";	
	if(ch==1){
		float fToM=ob.ft*0.3;	float iToC=ob.in*2.54;
		int a=(fToM+om.m)*100;		int b=iToC+om.cm;		
		if(a%100!=0){
			b+=(a%100);		
			a/=100;
			if(b/100>0){
				a+=b/100;
				b%=100;
			}		
		}
		om.display(a,b);
	}
	else{
		float mToF=om.m*3.28;	float cToI=om.cm*0.39;
		int x=(ob.ft+mToF)*12; 	int y=ob.in+cToI;
		if(x%12!=0){
			y+=(x%12);		
			x/=12;
			if(y/12>0){
				x+=y/12;
				y%=12;
			}		
		}	
		ob.display(x,y);	
	}	
}
int main(){
	int a,b,c,d,ch;
	cout<<"Enter m and cm: ";	cin>>a>>b;
	cout<<"Enter ft and inches: "; cin>>c>>d;
	DB ob(c,d);
	DM om(a,b);
	om.display();
	ob.display();
	do{
		cout<<"Enter 1 to display in metres and 2 to display in feet.   ";
		cin>>ch;
	}while(ch!=1&&ch!=2);
	add(ob,om,ch);
	return 0;
}
