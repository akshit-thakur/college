#include<fstream>
#include<iostream>
using namespace std;
int main(int argc,char* argv[]){
	ifstream fin;
	ofstream fout;
	fin.open(argv[2]);
	fout.open(argv[3]);
	while(fin){					
		char ch=fin.get();
		fout<<ch;
	}
	fin.close();
	fout.close();
	return 0;
}
