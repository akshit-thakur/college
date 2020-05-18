#include<fstream>
#include<iostream>
using namespace std;
int main(){
	char data[100];
	/**ofstream outfile; //outfile is obj of ofstream //data will go to file
	outfile.open("akshit@Akshit-Vostro-2520:~/Documents/Assignments/abc.txt"); //no need to specify mode,coz ofstream has default mode open..... file should exist!!
	cout<<"Writing to the file"<<endl;
	cout<<"Enter your name: ";
	cin.getline(data,100);
	cout<<data;
	outfile<<data<<endl;
	outfile.close();*/ //Documents/Assignments/abc.txt
	ifstream infile; //data will come from file
	infile.open("abc.txt");
	cout<<"Reading from file\n";	
	infile>>data;
	cout<<data<<endl;
	infile.close();
	return 0;
}
/** 
HEADER FILES
ofstream 
ifstream
fstream	--- No default mode

void open(const char* filename,ios:openmode);		//member of all 3
ios:app	--- append
ios:ate	--- at the end
ios:in --- default in ifstream
ios:out --- default in ofstream
ios:trunc --- deletes existing data in file when opened.
*/
