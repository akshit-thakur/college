#include<fstream>
#include<iostream>
using namespace std;
int main(int argc,char* argv[]){
	ifstream fin;
	ofstream fout;
	fin.open(argv[2],ios::ate);
	fout.open(argv[3]);
	int p=fin.tellg();
	while(p>0){
		fin.seekg(p-1);
		char ch=fin.get();
		fout<<ch;
		p-=1;
	}
	return 0;
}
