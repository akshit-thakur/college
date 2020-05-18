#include<iostream>
using namespace std;
class Student{
    protected:
    int rno;
    public:
    void getNum(){
		cout<<"Enter roll number: \n";
		cin>>rno;
    }
    void putNum(){
		cout<<"Roll number: \n"<<rno<<"\n";	
	}
};
class Test:public Student{
	protected: 
	int m1,m2;
	public:
	void getMarks(){
		cout<<"Enter marks of 2 subjects: \n";
		cin>>m1>>m2;	
	}
	void putMarks(){
		cout<<"Marks of 2 subjects are : \n"<<m1<<"\n"<<m2<<"\n";
	}
};
class Sports{
	protected:
	int sMarks;
	public:
	void getSports(){
		cout<<"Enter marks obtained in sports: \n";
		cin>>sMarks;	
	}
	void putSports(){
		cout<<"Marks obtained in sports are : \n"<<sMarks<<"\n";
	}
};
class Result:public Test,public Sports{
	int total;
	public:
	void display(){
		total=m1+m2+sMarks;
		putNum();
		putMarks();
		putSports();
		cout<<"Total : "<<total<<"\n";
	}
};
int main(){
	Result obj;
	obj.getNum();
	obj.getMarks();
	obj.getSports();
	obj.display();
	return 0;
}
