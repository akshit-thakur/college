#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
class Inventory{
	char name[10];
	int code;
	float cost;
	public:
	void getData(){
		cout<<"Enter name: "; cin>>name;
		cout<<"Enter code: "; cin>>code;
		cout<<"Enter cost: "; cin>>cost;
	}
	void putData(){
		cout<<setiosflags(ios::left)<<setw(10)<<name
			<<setiosflags(ios::right)<<setw(10)<<code
			<<setprecision(2)<<setw(10)<<cost<<endl;
	}
};
int main(){
	Inventory item;
	fstream f;
	f.open("Stock.txt",ios::ate|ios::in|ios::out|ios::binary);
	f.seekg(0,ios::beg);
	cout<<"CURRENT CONTENTS OF STOCK\n";
	while(f.read((char*)&item,sizeof(item)))
		item.putData();
	f.clear();	//turn off EOF flag
	/*>>>>>>>>>>>>>>>>> ADD ONE MORE ITEM <<<<<<<<<<< */
	cout<<"\nADD AN ITEM\n";
	item.getData();
	char ch;
	cin.get(ch);
	f.write((char*)&item,sizeof(item));
	//Display the appended file
	f.seekg(0);
	cout<<"Contents of appended file\n";
	while(f.read((char*)&item,sizeof(item)))
		item.putData();
	//Find number of obj in file
	cout<<"Enter object number to be updated\n";
	int objNum;
	cin>>objNum;
	cin.get(ch);
	int location=(objNum-1)*sizeof(item);
	if(f.eof())
	f.clear();
	f.seekp(location);
	cout<<"Enter new values of object\n";
	item.getData();
	cin.get(ch);
	f.write((char*)&item,sizeof(item))<<flush;
	/**>>>>>>>>>>>>>>> SHOW UPDATED FILE <<<<<<<<<<<<< */
	f.seekg(0);
	cout<<"Contents of updated file...\n";
	while(f.read((char*)&item,sizeof(item)))
		item.putData();
	f.close();		
	return 0;
}
