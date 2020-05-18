//To remove trailing whitespaces from end of all lines
/*i.e. to convert
int main(){
	int a,b,c;		'\n'
}
to
int main(){
a,b,c;'\n'
}
for more accurate file comparison
*/
#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main(int argc,char* argv[]){
	int flag=0;
	if(argc!=3){
		cout<<"Unequal number of argumets. Terminating!\n";
		exit(1);	
	}
	ifstream fs,ft;
	fs.open(argv[1]);
    ft.open(argv[2]);
    ofstream fout;
	fout.open("Temp");
	while(fs){
		char ch=fs.get();
		if(ch!=' ')
		fout<<ch;
		if(ch=='\n'){
			while(fs){
				ch=fs.get();
				if(ch=='/'||ch=='}'||ch=='{'||ch=='#'||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
				break;
			}
			fout<<ch;
		}
	}
	fs.close();
	fout.close();
	fout.open("temp");
	while(ft){
		char ch=ft.get();
		if(ch!=' ')//ch!='\n')
		fout<<ch;
		if(ch=='\n'){
			while(ft){
				ch=ft.get();
				if(ch=='/'||ch=='}'||ch=='{'||ch=='#'||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
				break;
			}
			fout<<ch;
		}
	}    
	ft.close();
	fout.close();
	fs.open("Temp");
	ft.open("temp");
    int s=0,t=0,sl=1,lt=1;
	while(fs){
		char cs=fs.get();
		char ct=ft.get();
		if(cs!=' ') s+=cs;
		if(ct!=' ') t+=ct;
		if(cs!=ct){
			flag=1;
			cout<<"Source line: "<<sl<<" Target line: "<<lt<<"\n\nSource character \" "<<cs<<"\" Target character \" "<<ct<<"\"\n\n\n";
			break;
		}
		if(cs=='\n') sl+=1;
		if(ct=='\n') lt+=1;
	}
	if(s!=t){
		flag=1;
		cout<<"source has: "<<s<<" Target has: "<<t<<"\n";
	}
	if(flag==0)
	cout<<"Same file content\n";
	else
	cout<<"Not the same file content\n";
	fs.close();
	ft.close();
	return 0;
}
