#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class Telephone{
	char name[10];
	char num[10];
	public:
	void getData(){
		cout<<"Enter name and number:\n";
		cin>>name>>num;	
	}
	void putData(){
		cout.width(15);
		cout<<setw(15)<<setiosflags(ios::left)<<name<<setw(15)<<setiosflags(ios::right)<<num<<"\n";	
	}
};
int main(){
	Telephone obj[2];
	int i;
	for(i=0;i<2;i++)	
	obj[i].getData();
	for(i=0;i<2;i++)
	obj[i].putData();
	fstream f;
	f.open("Directory.txt",ios::out);
	for(i=0;i<2;i++)	
	f.write((char*)&obj[i],sizeof(obj[i]));	
	return 0;
}
