//ERROR IN COPYING
#include<fstream>
#include<iostream>
using namespace std;
int main(){
	//writing to 2 files using open()
	ofstream fout; 
	int r,m;
	char name[10];
	fout.open("Student.txt");
	cout<<"Enter roll number and name:\n";
	cin>>r>>name;
	fout<<"Roll Number: "<<r<<"\n"<<"Name: "<<name<<"\n";
	fout.close();
	fout.open("Marks.txt");
	cout<<"Enter marks:\n";
	cin>>m;
	cout<<"\n"; //for formatting
	fout<<"Marks of roll number "<<r<<" are: "<<m<<"\n";
	fout.close();
	//reading file
	ifstream fin;
	char str[50];
	fin.open("Student.txt");	
	while(fin){
		fin.getline(str,50);
		cout<<str<<"\n";	
	}
	fin.close();
	fin.open("Marks.txt");	
	while(!(fin.eof())){
		fin.getline(str,50);
		cout<<str<<"\n";	
	}
	fin.close();
	//reading file character by character
	fin.open("Student.txt");
	cout<<"Reading character by character...\n";
	while(fin){
		char ch=fin.get();
		cout<<ch;	
	}		
	fin.close();
	//copying Student.......ERROR IN COPYING
	cout<<"Copying student data(excluding marks)..\n";
	fin.open("Student.txt");
	fout.open("StudentCopy.txt");
	while(!(fin.eof())){
		char ch=fin.get();	
		fout<<ch;	
	}
	fin.close();
	fout.close();
	return 0;
}
