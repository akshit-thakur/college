#include<iostream>
#include<fstream>
#include <string>
using namespace std;
int main(){
	char str[30];
	cin>>str;
    fstream f;
    f.open("text.txt",ios::in|ios::out);
    for(int i=0;str[i]!='\0';i++)
    	f.put(str[i]);
    f.seekg(0);
    while(f){
    	char ch=f.get();
    	cout<<ch;
    }
    f.close();
	return 0;
}
