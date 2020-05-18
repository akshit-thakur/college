#include<iostream>
using namespace std;
class Person{
	protected:
    char name[50];
	int code;
	public:
	void getPerson(){
		cout<<"Enter name: ";
		cin>>name;
		cout<<"Enter code: ";
		cin>>code;	
	}
	void showPerson(){
		cout<<"Name: "<<name<<"\n";
		cout<<"Code: "<<code<<"\n";
	}
};
class Account:public virtual Person{
	protected:
	float pay;
	public:
	void getAccount(){
		cout<<"Enter pay: ";
		cin>>pay;		
	}
	void showAccount(){
		cout<<"Pay: "<<pay<<"\n";
	}
};
class Admin:public virtual Person{
	protected: 
	int experience;
	public:
	void getAdmin(){
		cout<<"Enter experience in years: ";
		cin>>experience;			
	}
	void showAdmin(){
		cout<<"Experience "<<experience<<"\n";
	}
};
class Master:public Admin,public Account{
	public:
	void getData(){
		getPerson();
		getAccount();
		getAdmin();	
	}
	void showData(){
		showPerson();
		showAccount();
		showAdmin();			
	}
};
int main(){
	Master obj[3];
	int i;
	for(i=0;i<3;i++)
	obj[i].getData();
	for(i=0;i<3;i++)
	obj[i].showData();
}
