#include<iostream>
#include<string.h>
using namespace std;
class String{
	char n[100];
	public:
	String(char s[100]){
		int i;		
		for(i=0;s[i]!='\0';i++)
		n[i]=s[i];
		n[i]='\0';
	}
	int operator ==(String &s2){
		int a=strlen(n),b=strlen(s2.n);
		if(a==b) return 1;
		else return 0;
	}
};
int main(){
	String s1("Akshit"),s2("Thakur");
	if(s1==s2)
	cout<<"equal in length\n";
	return 0;
}
