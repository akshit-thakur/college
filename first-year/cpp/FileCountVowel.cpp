#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;	
int main(){
	fstream f;
	char str[30];
	cout<<"Enter file name: ";
	cin>>str;
	int countV=0,countW=1;
	f.open(str,ios::in);
	while(f){
		char ch=f.get();
		switch(ch){
			case ' ': countW++; break;
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u': countV++;		
		}
	}
	cout<<"Number of vowels is: "<<countV<<"\n";
	cout<<"Number of words is: "<<countW<<"\n";
	return 0;
}
