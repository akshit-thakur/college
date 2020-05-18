#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
class Inventory{
	char name[10];
	int code;
	float cost;
	public:
	void readData(){
		cout<<"Enter name: "; cin>>name;
		cout<<"Enter code: "; cin>>code;
		cout<<"Enter cost: "; cin>>cost;
	}
	void writeData(){
		cout<<setiosflags(ios::left)<<setw(10)<<name
			<<setiosflags(ios::right)<<setw(10)<<code
			<<setprecision(2)<<setw(10)<<cost<<endl;
	}
};
int main(){
	Inventory item[3];
	fstream f;
	int i;
	f.open("Stock.txt",ios::in|ios::out);
	cout<<"ENTER DETAILS OF THREE ITEMS\n";
	for(i=0;i<3;i++){
		item[i].readData();
		f.write((char*)&item[i],sizeof(item[i]));	
	}
	f.seekg(0);
	cout<<"\nOUTPUT\n\n";
	for(i=0;i<3;i++){
		f.read((char*)&item[i],sizeof(item[i]));
		item[i].writeData();	
	}
	f.close();
	return 0;
}
