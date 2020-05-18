#include<fstream>
#include<iostream>
#include<stdlib.h>
using namespace std;
int main(int argc,char* argv[]){
	fstream f;
	if(argc!=3){	
		cout<<"Insufficient arguments.3 required. Exiting....\n";
		exit(1);	
	}
	f.open(argv[2],ios::in);
	while(f){
		char ch;
		f.get(ch);
		cout<<ch;
	}
}
