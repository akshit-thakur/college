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
    seekp(0,ios::end);
    const int size=tellp();
    seekp(0,ios::beg);
    ft.open(argv[2]);
    seekp(0,ios::end);
    const int size1=tellp();
    seekp(0,ios::beg);
    char arr[size],arr1[size1];
    int count=0;
    while(fs){
		char ch=fs.get();
		if(ch!=' ')
		arr[count++]ch;
		if(ch=='\n'){
			while(fs){
				ch=fs.get();
				if(ch=='/'||ch=='}'||ch=='{'||ch=='#'||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
				break;
			}
			arr[count++]=ch;
		}
	}
	fs.close();
	int count1=0;
	while(ft){
		char ch=ft.get();
		if(ch!=' ')//ch!='\n')
		arr1[count1++]ch;
		if(ch=='\n'){
			while(ft){
				ch=ft.get();
				if(ch=='/'||ch=='}'||ch=='{'||ch=='#'||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
				break;
			}
			arr1[count1++]ch;
		}
	}    
	ft.close();
	if(count1!=count){
		flag=1;
		cout<<"source has: "<<count1<<" Target has: "<<count<<"\n";
	}
	if(flag==0)
	cout<<"Same file content\n";
	else
	cout<<"Not the same file content\n";
	fs.close();
	ft.close();
	return 0;
}
