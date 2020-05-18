#include<fstream>
#include<iostream>
using namespace std;
class Student{
	int r;
	float m;
	char n[10];
	public:
	void getData(){
		cout<<"Enter roll number: "; cin>>r;
		cout<<"Enter name: ";	cin>>n;
		cout<<"Enter marks: ";	cin>>m;	
	}
	void addRecord(){
		fstream f;
		f.open("Student",ios::app|ios::binary);
		Student obj;
		obj.getData();
		f.write((char*)&obj,sizeof(obj));
	}
};
int main(){
	Student s;
	char ch='N';
	do{
		s.addRecord();
		cout<<"Add another record? Y/N: ";
		cin.get(ch);
	}while(ch=='y'||ch=='Y');
	return 0;
}
