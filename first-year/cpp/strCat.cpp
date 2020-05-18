#include<iostream>
#include<string.h>
using namespace std;
class S2;
class S3;
class S1{
	char* str1;
	int len1;
	public:
	S1(){
		len1=0;
		str1=new char[len1+1];
	}
	friend void getData(S1 &x,S2 &y);
	friend void concatStr(S1 &x,S2 &y,S3 &z);
	friend void display(S1 &x,S2 &y,S3 &z);
};
class S2{
	char* str2;
	int len2;
	public:
	S2(){
		len2=0;
		str2=new char[len2+1];
	}
	friend void getData(S1 &x,S2 &y);
	friend void concatStr(S1 &x,S2 &y,S3 &z);
	friend void display(S1 &x,S2 &y,S3 &z);
};
class S3{
	char* str3;
	int len3;
	public:
	S3(){
		len3=0;
		str3=new char[len3+1];
	}
	friend void concatStr(S1 &x,S2 &y,S3 &z);
	friend void display(S1 &x,S2 &y,S3 &z);
};
void getData(S1 &x,S2 &y){
	char a[30]; char b[30];
	cout<<"Enter 2 strings: \n";
	cin.getline(a,30);
	cin.getline(b,30);
	strcpy(x.str1,a);
	strcpy(y.str2,b);
	x.len1=strlen(x.str1);
	y.len2=strlen(y.str2);
}
void concatStr(S1 &x,S2 &y,S3 &z){
	z.len3=x.len1+y.len2;
	delete z.str3;
	z.str3=new char[z.len3+1];
	strcpy(z.str3,x.str1);
	strcat(z.str3,y.str2);
}
void display(S1 &x,S2 &y,S3 &z){
	cout<<x.str1<<"\n"<<y.str2<<"\n"<<z.str3<<"\n";
}
int main(){
	S1 x; S2 y; S3 z;
	getData(x,y);
	concatStr(x,y,z);
	display(x,y,z);
};
