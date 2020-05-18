#include<iostream>
#include<string.h>
using namespace std;
class String{
	char* name;
	int len;
	public:
	String(){}
	String(const char* n){
		len=strlen(n);
		name=new char[len+1];
		strcpy(name,n);
	}
	void show(){
		cout<<name<<"\n";
	}
	String operator +(String &b){
		String temp;
		temp.len=len+b.len;
		temp.name=new char[temp.len+1];
		strcpy(temp.name,name);
		strcat(temp.name,b.name);
		return temp;
	}
};
int main(){
    String s1="Punjab";
    String s2=" University";
    String s3;
    s3=s1+s2;
    s1.show();
    s2.show();
    s3.show();
	return 0;
}

