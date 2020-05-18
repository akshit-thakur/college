#include<iostream>
#include<string.h>
using namespace std;
class Strings{
	int len;
	char* name;
	public:
	Strings(){
		len=0;
		name=new char[len+1];	
	}
	Strings(char* str){
		len=strlen(str);
		name=new char[len+1];
		strcpy(name,str);	
	}
	void join(Strings &a,Strings &b){
		len=a.len+b.len;	
		delete name;
		name=new char[len+1];
		strcat(name,a.name);
		strcat(name,b.name);
	}
	void disp(){
		cout<<name<<"\n";
	}
};
int main(){
	Strings s1("A"),s2("B"),s3("C");
	Strings s4,s5;
	s4.join(s1,s2);
	s5.join(s4,s3);
	s1.disp();
	s2.disp();
	s3.disp();
	s4.disp();
	s5.disp();
	return 0;
}
