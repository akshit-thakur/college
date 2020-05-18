#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main(){
	const int SIZE=80;
	char line[SIZE];
	ifstream fin1,fin2;
	fin1.open("Country.txt");
	fin2.open("City.txt");
	if(!fin1){
		cout<<"Exit from file 1\n";
		exit(1);
	}
	if(!fin2){
		cout<<"Exit from file 2\n";
		exit(2);
	}			
	for(int i=1;i<=10;i++){
		if(!fin1){
			cout<<"Exit from file 1\n";
			exit(1);
		}		
		if(!fin2){
			cout<<"Exit from file 2\n";
			exit(2);
		}		
		fin1.getline(line,SIZE);
		cout<<"Capital of "<<line<<"\n";
		fin2.getline(line,SIZE);
		cout<<line<<"\n";
	}	
	return 0;
}
