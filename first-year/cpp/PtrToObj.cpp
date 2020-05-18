#include<iostream>
#include<string.h>
using namespace std;
class City{
	char* name;
	int len;
	public:
	City(){ len=0; name=new char[len+1]; }
	void getName(){
		char s[30];
		cout<<"Enter city name: ";
		cin>>s;
		len=strlen(s);
		name=new char[len+1];
		strcpy(name,s);	
	}
	void showName(){
		cout<<name<<"\n";
	}
};
int main(){
	int i,n=0;
	City *cptr[5];
	for(i=0;i<5;i++){
		cptr[n]=new City;
		cptr[n]->getName();
		n++;	
	}
	for(i=0;i<5;i++)
		cptr[i]->showName();
	return 0;
}
