#include<iostream>
#include<string.h>
using namespace std;
class String{
	char str[30];
	public:
	void input(){ cin>>str; }
	void show(){ cout<<str<<"\n"; }
	friend String operator &&(String&,String&);
};
String operator &&(String &s,String &t){
	String temp;
	strcpy(temp.str,s.str);
	strcat(temp.str,t.str);
	return temp;
}
int main(){
	String s1,s2;
	s1.input();
	s2.input();
	String s3=s1&&s2;
	s1.show();
	s2.show();
	s3.show();
}
