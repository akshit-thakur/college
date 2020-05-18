#include<iostream>
using namespace std;
class Student{
	int rno;
	char* name;
	int m1,m2,total;
	float avg;
	public:
	void get(){
		cout<<"Enter roll number: "; cin>>rno;
		cout<<"Enter name: "; cin>>name;
		cout<<"Enter marks of 2 subjects:\n"; cin>>m1>>m2;
		total=m1+m2;
		avg=total/2.0;
	}
	void put(){
		cout<<"Roll Number "<<rno<<"\n";
		cout<<"Name "<<name<<"\n";
		cout<<"Marks 1 "<<m1<<"\n"<<"Marks 2 "<<m2;
		cout<<"Total "<<total<<"\n"<<"Avg "<<avg<<"\n\n";
	}
};
int main(){
	Student s[5]; int i;
	for(i=0;i<5;i++)
		s[i].get();
	for(i=0;i<5;i++)
		s[i].put();
	return 0;
}
