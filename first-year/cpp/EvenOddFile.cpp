#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;
int main(int argc,char* argv[]){
	int number[9]={11,22,33,44,55,66,77,88,99};
	if(argc!=4){
		cout<<"Error in arguments!\n"<<argc<<" found, 4 needed\n";
		exit(1);
	}
	ofstream fout1,fout2;
	fout1.open(argv[2]);
	if(fout1.fail()){
		cout<<"Couldn't open "<<argv[2]<<"\n";			
		exit(2);	
	}
	fout2.open(argv[3]);
	if(fout2.fail()){
		cout<<"Couldn't open "<<argv[3]<<"\n";			
		exit(3);	
	}
	int i;
	for(i=0;i<9;i++){
		if(number[i]%2!=0)
		fout2<<number[i]<<" ";
		else
		fout1<<number[i]<<" ";	
	}
	fout1.close();
	fout2.close();
	ifstream fin;
	char ch;
	for(i=2;i<argc;i++){
		fin.open(argv[i]);
		cout<<"Reading from "<<argv[i]<<"....\n";		
		while(fin){
			fin.get(ch);
			cout<<ch;
		}
		cout<<"\n\n";
		fin.close();
	}
	return 0;
}
