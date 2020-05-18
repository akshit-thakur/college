#include<iostream>
#include<string.h>
using namespace std;
const int SIZE=10;
int count=0;
class Employee{
	int ecode;
	char* ename;
	char* dept;
	float salary;
	char* date; 
	public:
	Employee(){
		ename=new char[1];
		dept=new char[1];
		date=new char[1];
		strcpy(ename,"");
		strcpy(dept,"");
		strcpy(date,"");
		salary=0.0;
		ecode=0;
	}
	Employee(int c,char* n,char* d,float s,char* j){
		ename=new char[strlen(n)+1];
		dept=new char[strlen(d)+1];
		date=new char[strlen(j)+1];
		strcpy(ename,n);
		strcpy(dept,d);
		strcpy(date,j);
		ecode=c;
		salary=s;
	}
	void display(){
		cout<<"Code: "<<ecode<<"\n";
		cout<<"Name: "<<ename<<"\n";
		cout<<"Dept: "<<dept<<"\n";
		cout<<"Salary: "<<salary<<"\n";
		cout<<"Date of joining: "<<date<<"\n\n";
	}
	int search(int c,char* n){
		if(ecode==c&&strcmp(ename,n)==0)
			return 1;
		else
			return 0;
	}
	void update(float s){
		salary=s;
	}
};
int main(){
	int i,choice;
	char n[50];
	char d[20];
	char j[10];
	float s;
	int c;
    Employee *obj[SIZE];
    do{
		cin.sync();
		cout<<"1.Add new record\n2.Update salary\n3.Display Data\n4.Search by name and code\n5.Exit\n";    	
		cin>>choice;
		switch(choice){
			case 1:
			if(count!=SIZE){
				cout<<"Enter code,name,dept,salary & date of joining(DD/MM/YYYY):\n";
				cin>>c>>n>>d>>s>>j;
				obj[count++]=new Employee(c,n,d,s,j);
			}
			else
			cout<<"Too many records! unable to store...\n";
			break;
			case 2:
			cout<<"Enter employee code & name to update salary of: ";
			cin>>c>>n;
			for(i=0;i<count;i++){
				if(obj[i]->search(c,n)){
					cout<<"Enter new salary: ";
					cin>>s;
					obj[i]->update(s);
					break;
				}
			}
			if(i==count)
				cout<<"Employee Record not found\n";	
			break;
			case 3:
			cout<<"The record of all the employees is: \n";
			for(i=0;i<count;i++)
				obj[i]->display();
			break;
			case 4:
			cout<<"Enter the employee's code and name:\n";
			cin>>c>>n;
			for(i=0;i<count;i++){
				if(obj[i]->search(c,n)){
					cout<<"Success!! Employee record found\n";
					cout<<"Here are the details:\n";
					obj[i]->display();
					break;
				}
			}
			if(i==count)
				cout<<"Employee Record not found\n";
			break;
		}
    }while(choice!=5);
	return 0;
}
